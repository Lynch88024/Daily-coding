#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int maxm = 1010;

int w[maxn], c[maxn], dp[maxm];

void F(int t, int m)
{
    for(int i=0; i<=t; i++)
    {
        dp[i] = 0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=t; j>=w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int t, m;
    scanf("%d %d", &t, &m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &w[i], &c[i]);
    }
    F(t, m);
   // sort(dp, dp+t+1, cmp);
    printf("%d\n", dp[t]);

    return 0;
}