#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
char input[maxn];
char output[maxn];
bool dp[maxn][maxn] = {false}; // dp[i][j]表示字符子串i到j是否为回文

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        getchar();
        gets(input);
        int len = strlen(input);
        
        int left, right; // 最长回文子串的起点&终点
        for(int j=0; j<len; j++) // j为右端点
        {
            for(int i=0; i<=j; i++) // i为左端点
            {
                if(j-i==0 || j-i==1) // 奇数点对称 & 偶数点对称 两种情况
                {
                    dp[i][j] = (input[i]==input[j]);
                }
                else if(j-i > 1)
                {
                    dp[i][j] = (input[i]==input[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==true && j-i+1>ans) // 更新最长回文子串
                {
                    ans = j-i+1;
                    left = i;
                    right = j;
                    for(int k=left; k<=right; k++) // 存储子串
                    {
                        output[k-left] = input[k];
                    }
                    output[ans] = '\0';
                }
            }
        }
    }

    for(int i=0; i<strlen(output); i++) // 输出结果
    {
        printf("%c", output[i]);
    }
    printf("\n");

    return 0;
}