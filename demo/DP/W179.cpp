#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int maxv = 2010;
int h[maxv], p[maxv], dp[maxn];  
int cnt = 0;

void F(int n, int V)
{
    for(int i=0; i<=V; i++)
    {
        dp[0] = 0;
    }
    for(int i=1; i<=cnt; i++)
    {
        for(int v=V; v>=p[i]; v--) 
        {
            dp[v] = max(dp[v], dp[v-p[i]]+h[i]); 
        }
    }
    printf("%d", dp[V]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int p_, h_, k;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &p_, &h_, &k);
        int c = 1;
        while( k-c>0 )
        {
            k -= c;
            cnt++;
            p[cnt] = c*p_;
            h[cnt] = c*h_;
            c *= 2;
        }
        cnt++;
        p[cnt] = k*p_;
        h[cnt] = k*h_;
    }
    F(m, n);

    return 0;
}