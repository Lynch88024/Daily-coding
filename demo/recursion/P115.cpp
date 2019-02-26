/*
*   全排列 —— 1~n这n个数的组合按字典序排列
*   方法:   递归 
*   @author Lynch <2628477079@qq.com>
*/

#include <cstdio>

const int maxn = 11;
int n;
bool hashtable[maxn] = {false};
int P[maxn];

void F(int index)
{
    if(index == n+1) // 调用F(n)时，P[n]还没有值，所以要等到 index==n+1 才到达终止条件
    {
        for(int i=1; i<=n; i++)
        {
            printf("%d ", P[i]);
        }
        printf("\n");
    }
    for(int x=1; x<=n; x++)
    {
        if(hashtable[x] == false)
        {
            P[index] = x; // 因为P[1]无初始值，所以需向ans[index]赋值
            hashtable[x] = true;
            F(index+1);
            hashtable[x] = false;
        }
    }
}

int main()
{
    n = 3;
    F(1);

    return 0;
}

