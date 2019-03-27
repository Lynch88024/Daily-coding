#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int flag[maxn]; 

void findPrime() // 得到素数表
{
    for(int i=2; i<maxn; i++)
    {
        if(flag[i] == 1) // 找到第一个素数，其倍数都为非素数
        {
            for(int j=i+i; j<maxn; j+=i)
            {
                flag[j] = 0; // 置为非素数
            }
        }
    }
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(y < x)
    {
        swap(x, y);
    }
    fill(flag, flag+maxn, 1);  // 先假设所有数都为素数
    flag[1] = 0; // 1不是素数
    int ans = 0;
    findPrime();
    for(int i=x; i<=y; i++)
    {
        ans += flag[i];
    }
    printf("%d", ans);

    return 0;
}