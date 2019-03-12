#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 

const int maxn = 105;
int a[maxn], dp[maxn];
bool ddpp[maxn] = {false};

int F(int n) // 递归
{
    if(n == 0)
    {
        return a[0];
    }
    if(ddpp[n] == true) 
    {
        return dp[n]; 
    }
    else
    {
        ddpp[n] = true;
        dp[n] = max(F(n-1)+a[n], a[n]);
        return dp[n];
    }
}

void FF(int n) // 递推
{
    dp[0] = a[0];
    for(int i=1; i<n; i++)
    {
        dp[i] = max(dp[i-1]+a[i], a[i]);
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n = 6;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    F(n);
    sort(dp, dp+n, cmp);
    printf("%d", dp[0]);

    return 0;
}