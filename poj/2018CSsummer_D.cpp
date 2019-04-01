/*
背包问题中，正好将包装满问题：
若要求的是最小值，dp[0]=0，其他dp值设为最大值 0x7fffffff;
若要求的是最大值，dp[0]=0，其他dp值设为最小值 0xffffffff;

0-1背包 与 完全背包：
0-1背包：从maxn到装包元素a[i]遍历(逆序遍历);
完全背包：从装包元素a[i]到maxn遍历(顺序遍历);
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff

const int maxn = 2100; // 这里不能写100,因为本题涉及减的操作，所以中间状态非常有可能大于100
int dp[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int coin[10];
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=6; j++)
        {
            scanf("%d", &coin[j]);
        }
        dp[0] = 0;                 // 正好相等问题的初始化方式
        for(int j=1; j<=maxn; j++)
        {
            dp[j] = INF;
        }
        // 两遍完全背包
        for(int j=1; j<=6; j++) // 付钱过程中一直加
        {
            for(int v=coin[j]; v<=maxn; v++)
            {
                if(dp[v-coin[j]] != INF)
                {
                    dp[v] = min(dp[v], dp[v-coin[j]]+1); 
                }
            }
        }
        for(int j=1; j<=6; j++) // 找钱过程中一直减
        {
            for(int v=maxn-coin[j]; v>=0; v--)
            {
                if(dp[v+coin[j]] != INF)
                {
                    dp[v] = min(dp[v], dp[v+coin[j]]+1);  
                }
            }
        }
        int sum = 0, max_ = -1;
        for(int j=1; j<=100; j++)
        {
            sum += dp[j];
            max_ = max(max_, dp[j]);
        }
        double ave = (double)sum / 100;
        printf("%.2lf %d\n", ave, max_);
    }
    fclose(stdin);

    return 0;
}