#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int A[maxn], dp[maxn];

void FF(int n)
{
    for(int i=1; i<=n; i++)
    {
        dp[i] = 1;
        for(int j=1; j<i; j++)
        {
            if(A[j] <= A[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
            
            // if(A[j]<=A[i] && dp[j]+1>dp[i])
            // {
            //     dp[i] = dp[j] + 1;
            // }
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
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &A[i]); 
    }
    FF(n);
    sort(dp+1, dp+1+n, cmp);
    printf("%d", dp[1]); 

    return 0;
}