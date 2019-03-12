// 数塔问题

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
int f[maxn][maxn];// = {{0},{0,5},{0,8,3},{0,12,7,16},{0,4,10,11,6},{0,9,5,3,9,4}};
int dp[maxn][maxn];

int F(int i, int j, int n) // 递归
{
    if(i == n)
    {
        dp[i][j] = f[i][j];
        return dp[i][j];
    }
    if(dp[i][j] > 0)
    {
        return dp[i][j];
    }
    else
    {
        dp[i][j] = max(F(i+1, j, n), F(i+1, j+1, n)) + f[i][j]; 
        return dp[i][j];
    }    
}

int FF(int n) // 递推
{
    for(int i=1; i<=n; i++)
    { 
        dp[n][i] = f[n][i];
    }
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
        }
    }
    return dp[1][1];
}

int main()
{
    int n = 5;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d", &f[i][j]);
        }
    }
    
    printf("%d", F(1,1,n));

    return 0;
}