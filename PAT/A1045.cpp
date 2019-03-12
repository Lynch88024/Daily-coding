#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 210;
const int maxm = 10010;
int L[maxm], C[maxn], dp[maxm], h[maxn] = {0};

void FF(int n)
{
    for(int i=0; i<n; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(h[L[j]]<=h[L[i]] && dp[j]+1>dp[i])
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
    int n, m, l;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &C[i]);
        h[C[i]] = i+1;
    }
    scanf("%d", &l);
    int cnt = 0, temp;
    for(int i=0; i<l; i++)
    {
        scanf("%d", &temp);
        if(h[temp] != 0)
        {
            L[cnt++] = temp;
        }
    }
    FF(cnt);
    sort(dp, dp+cnt, cmp);
    printf("%d", dp[0]);

    return 0;
}