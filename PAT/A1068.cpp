#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
const int maxm = 110;

int w[maxn], dp[maxm];
bool choice[maxn][maxm], flag[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &w[i]);
    }
    sort(w+1, w+1+n);
    for(int i=0; i<=m; i++)
    {
        dp[i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int v=m; v>=w[i]; v--)
        {
            if(dp[v] <= dp[v-w[i]] + w[i])
            {
                dp[v] = dp[v-w[i]] + w[i];
                choice[i][v] = true; // 放入第i件商品
            }
            else
            {
                dp[v] = dp[v];
                choice[i][v] = false; // 不放入第i件商品
            }
        }
    }

    if(dp[m] != m)
    {
        printf("No Solution");
    }
    else // 遍历choice[][]
    {
        int k = n, v = m, num = 0;
        while(k > 0) 
        {
            if(choice[k][v] == true)
            {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else 
            {
                flag[k] = false;
            }
            k--;
        }

        for(int i=n; i>=1; i--)
        {
            if(flag[i] == true)
            {
                printf("%d", w[i]);
                num--;
                if(num > 0)
                {
                    printf(" ");
                }
            }
        }
    }
    
    return 0;
}