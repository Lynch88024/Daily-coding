#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn], left_[maxn], right_[maxn];

void F(int n)
{
    dp[0] = A[0];
    left_[0] = 0;
    right_[0] = 0;
    for(int i=1; i<n; i++)
    {
        if(dp[i-1]+A[i] >= A[i])
        {
            dp[i] = dp[i-1] + A[i];
            left_[i] = left_[i-1];
            right_[i] = i;
        }
        else
        {
            dp[i] = A[i];
            left_[i] = i;
            right_[i] = i;   
        }
    }
}

int main()
{
    int n;
    bool flag = false;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
        if(A[i] >= 0)
        {
            flag = true;
        }
    }
    if(flag == false)
    {
        printf("%d %d %d\n", 0, A[0], A[n-1]);
    }
    else
    {
        F(n);
        int max_ = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i] > dp[max_])
            {
                max_ = i;
            }
        }
        printf("%d %d %d\n", dp[max_], A[left_[max_]], A[right_[max_]]);
    }

    return 0;
}