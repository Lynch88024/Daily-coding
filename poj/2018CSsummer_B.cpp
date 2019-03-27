#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
char input[maxn];
char output[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        getchar(); // 吸收上一次输入的回车符
        gets(input);
        int len = strlen(input);        
        // 先判断 对称点是 奇数点 情况
        for(int i=0; i<len; i++) // 遍历所有点，寻找子串对称点
        {
            int left = i;
            int right = i;
            while(left>0 && right<len-1 && input[left-1]==input[right+1]) // 判断选取的中心点的对称性
            {
                left--;
                right++;
            }
            if(right-left+1 > ans) // 更新最长子串长度
            {
                ans = right-left+1;
                for(int i=left; i<=right; i++)
                {
                    output[i-left] = input[i];
                }
                output[ans] = '\0';
            }
        }     
        // 再判断 对称点是 偶数点 情况
        for(int i=0; i<len; i++)
        {
            if(input[i] == input[i+1])
            {
                int left = i;
                int right = i+1;
                while(left>0 && right<len-1 && input[left-1]==input[right+1])
                {
                    left--;
                    right++;
                }
                if(right-left+1 > ans)
                {
                    ans = right-left+1;
                    for(int i=left; i<=right; i++)
                    {
                        output[i-left] = input[i];
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