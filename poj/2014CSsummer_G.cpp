#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3500;
const int maxv = 13000;

int dp[maxv], W[maxn], D[maxn];

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &W[i], &D[i]);
    }
    for(int v=0; v<=m; v++)
    {
        dp[v] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int v=m; v>=W[i]; v--)
        {
            dp[v] = max(dp[v], dp[v-W[i]]+D[i]);
        }
    }
    int max_ = 0;
    for(int v=0; v<=m; v++)
    {
        if(dp[v] > max_)
        {
            max_ = dp[v];
        }
    }
    printf("%d\n", max_);
    // fclose(stdin);

    return 0;
}