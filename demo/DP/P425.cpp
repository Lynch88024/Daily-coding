// 斐波那契数列 

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 110;
int dp[maxn] ;

int F(int n) // 递归
{
    if(n==0 || n==1)
    {
        return 1;
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
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<15; i++)
        printf("%d %d\n", F(i), FF(i));

    return 0;
}