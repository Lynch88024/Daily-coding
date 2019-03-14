#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
char A[maxn], B[maxn];
int dp[maxn][maxn];

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
            if(A[i] == B[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }    
        }
    }
}

int main()
{
    scanf("%s", A);
    scanf("%s", B);
    int len_a = strlen(A);
    int len_b = strlen(B); 
    FF(len_a, len_b);
    printf("%d", dp[len_a][len_b]);
    
    return 0;
}