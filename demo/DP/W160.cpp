#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 30;
int A[maxn], dp[maxn];

void FF(int n)
{
    for(int i=0; i<n; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(A[j]>=A[i] && dp[j]+1>dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }
    FF(n);
    sort(dp, dp+n, cmp);
    printf("%d", dp[0]);

    return 0;
}