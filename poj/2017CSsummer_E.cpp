#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 110;
int tower[maxn];
int dp_d[maxn]; // 以tower[i]为结尾的最长递减子序列长度为dp_d[i];
int dp_i[maxn]; // 以tower[i]为结尾的最长递减子序列长度为dp_i[i];

int LDS(int len) // 最长递减子序列
{
    int ans = -1;
    for(int i=0; i<len; i++) // 以tower[i]为结尾的串
    {
        dp_d[i] = 1; // 先初始化
        for(int j=0; j<i; j++)
        {
            if(tower[j]>=tower[i] && dp_d[j]+1>dp_d[i])
            {
                dp_d[i] = dp_d[j] + 1;
            }
        }
        ans = max(ans, dp_d[i]);
    }

    return ans;
}

int LIS(int len) // 最长递增子序列
{
    int ans = -1;
    for(int i=0; i<len; i++)
    {
        dp_i[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(tower[j]<=tower[i] && dp_i[j]+1>dp_i[i])
            {
                dp_i[i] = dp_i[j] + 1;
            }
        }
        ans = max(ans, dp_i[i]);
    }

    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int k;
    scanf("%d", &k);
    int n;
    for(int i=0; i<k; i++)
    {
        scanf("%d", &n);
        for(int j=0; j<n; j++)
        {
            scanf("%d", &tower[j]);
        }
        // 反向最长递减子序列=正向最长递增子序列
        int ans_i = LIS(n); // 反向跳跃等价于 最长递增子序列
        int ans_d = LDS(n); // 正向跳跃等价于 最长递减子序列 
        int ans = max(ans_i, ans_d); // 结果为二者中最大值
        printf("%d\n", ans);
    }
    // fclose(stdin);

    return 0;
}