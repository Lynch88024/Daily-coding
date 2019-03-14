#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 210;
const int maxm = 10010;
int C[maxn], L[maxm], dp[maxn][maxm];

void FF(int len_a, int len_b)
{
    for(int i=0; i<=len_a; i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0; i<=len_b; i++)
    {
        dp[0][i] = 0; 
    }
    for(int i=1; i<=len_a; i++)
    {
        for(int j=1; j<=len_b; j++)
        {
            if(C[i] == L[j])
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }  
        }
    }
}

int main()
{
    int n, m, l;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d", &C[i]);
    }
    scanf("%d", &l);
    for(int i=1; i<=l; i++)
    {
        scanf("%d", &L[i]);
    }
    FF(m, l);
    printf("%d", dp[m][l]);
    
    return 0;
}