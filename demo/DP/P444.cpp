#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int maxm = 1010;

int w[maxn], c[maxn], dp[maxm];

void F01(int n, int V) // 0-1背包问题
{
    for(int v=0; v<=V; v++)
    {
        dp[v] = 0; 
    }
    for(int i=1; i<=n; i++)
    {
        for(int v=V; v>=w[i]; v--)
        {
            dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
        }
    }
}

void Ftotal(int n, int V) // 完全背包问题
{
    for(int v=0; v<=V; v++)
    {
        dp[v] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int v=w[i]; v<=V; v++)
        {
            dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
        }
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, V;
    scanf("%d %d", &n, &V);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &w[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &c[i]);
    }
    Ftotal(n, V);
    //sort(dp, dp+V+1, cmp);
    printf("%d\n", dp[V]);

    return 0;
}