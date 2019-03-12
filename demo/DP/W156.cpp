#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;
int dp[maxn];

int F(int n) // 递归
{
    if(n==1 || n==2)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];       
    }
    else
    {
        dp[n] = F(n-1) + F(n-2);
        return dp[n];
    }  
}

int FF(int n) // 递推
{
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    int n = 4;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<15; i++)
        printf("%d %d\n", F(i), FF(i));

    return 0;
}