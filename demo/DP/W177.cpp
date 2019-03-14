#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int maxm = 10010;
#define INF 0x7fffffff

int w[maxn], c[maxn], dp[maxm];

void FF(int n, int V)
{
    dp[0] = 0;
    for(int i=1; i<=V; i++)
    {
        dp[i] = INF;
    }
    for(int i=1; i<=n; i++)
    {
        for(int v=w[i]; v<=V; v++)
        {
            if(dp[v-w[i]] != INF)
            {
                dp[v] = min(dp[v], dp[v-w[i]]+c[i]); 
            }
        }
    }
    if(dp[V] != INF)
    {
        printf("%d", dp[V]);
    }
    else
    {
        printf("ERROR\n");
    }   
}

int main()
{
    int E, F;
    scanf("%d %d", &E, &F);
    int n;
    scanf("%d", &n);
    int V = F - E; 
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &c[i], &w[i]);
    }
    FF(n, V);   

    return 0;
}