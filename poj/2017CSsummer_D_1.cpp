#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int target;
char str[30];
char ans[10], temp[10];
int len;
int flag = 0; // 判断是否存在解的标志
int visit[30] = {0}; // 记录字符串每位被访问过与否 

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

// DFS搜索到最后得到的是最后一组解，前边的解都会被覆盖
void DFS(int depth)
{
    if(depth >= 5) // 死胡同——搜索5个数，深度从0~4，也就是说深度为5时开始判断本次搜索成功与否
    {   // 加flag==0则从大到小排序，不加flag==0则从小到大排序
        if(judge(change(temp[0]),change(temp[1]),change(temp[2]),change(temp[3]),change(temp[4]))==true && flag==0) // 存在解
        {                      // flag==0 得到第一组解后不再对解更新，第一组解是字典序最大，如果不加这个条件，则最后得到的是最后一组解       
            flag = 1;          
            strcpy(ans, temp); // 将正确的解存入ans，第一次存入的即为字典序最大           
        }
        return ; // 从大到小排序、搜索，得到的第一组解便是字典序最大的解
    }
    // 岔路口——按层次进行探索，探索完成进行回溯
    for(int i=0; i<len; i++)
    {
        if(visit[i] == 0) // 未访问过的字符
        {
            temp[depth] = str[i]; // temp临时记录路径
            visit[i] = 1; // 记录已被访问过
            DFS(depth+1); // 向下一层搜索
            visit[i] = 0; // 回溯，恢复该位置的访问记录
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
    while(scanf("%d %s", &target, str) != EOF)
    {
        flag = 0;
        if(target==0 && strcmp(str,"END")==0)
        {
            break;
        }
        len = strlen(str);
        sort(str, str+len, cmp); // 从大到小排序
        DFS(0); // 搜索
        print();
    }
    // fclose(stdin);

    return 0;
}