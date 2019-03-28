// 可以用strcmp()函数来判断字符串的字典序排序
// 希望得到字典序最大的解 —— 从大到小排序，得到第一个解即返回 
//                         从小到大排序，一直遍历得到最后一个解返回

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int target;
char str[30];
char ans[10];
int flag = 0; // 判断是否存在解的标志

int change(char a)
{
    int t = a - 'A' + 1;
    return t;
}

bool judge(int a, int b, int c, int d, int e)
{
    if(a-b*b+c*c*c-d*d*d*d+e*e*e*e*e == target)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void code(int len)
{
    for(int a=0; a<len; a++)
    {
        for(int b=0; b<len; b++)
        {
            if(b == a)
            {
                continue;
            }
            for(int c=0; c<len; c++)
            {
                if(c==b || c==a)
                {
                    continue;
                }
                for(int d=0; d<len; d++)
                {
                    if(d==c || d==b || d==a)
                    {
                        continue;
                    }
                    for(int e=0; e<len; e++)
                    {
                        if(e==d || e==c || e==b || e==a)
                        {
                            continue;
                        }
                        if(judge(change(str[a]), change(str[b]), change(str[c]), change(str[d]), change(str[e])) == true)
                        {
                            flag = 1;
                            ans[0] = str[a];
                            ans[1] = str[b];
                            ans[2] = str[c];
                            ans[3] = str[d];
                            ans[4] = str[e];
                            return ; // 从大到小遍历，得到的第一个解便是字典序最大的解
                        }
                    }
                }
            }
        }
    }   
}

void print()
{
    if(flag == 0) 
    {
        printf("no solution\n");
    }
    else 
    {
        for(int i=0; i<5; i++)
        {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
}

bool cmp(char a, char b)
{
    return a > b;
}

int main()
{   
    // freopen("input.txt","r",stdin);
    while(scanf("%d %s", &target, str)!=EOF)
    {
        flag = 0; // 每次判断前要把上次的标志恢复
        if(target==0 && strcmp(str,"END")==0)
        {
            break;
        }
        int len = strlen(str);
        // 当从小往大查询，查询的数依次增大，最终得到的结果必定是字典序号和最大的
        // 当从大往小查询，得到的第一个解则是字典序号和最大的
        sort(str, str+len, cmp); // 从大到小排序
        code(len);
        print();
    }
    // fclose(stdin);

    return 0;
}