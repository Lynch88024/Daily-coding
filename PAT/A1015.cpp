#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int z[40], num = 0; // 数组z存放结果的每一位(由高位向低位输出)，num为位数

int to_D(int x, int p) // 将p进制数x转换为十进制
{
    int ans = 0, product = 1;
    while(x != 0)
    {
        ans += (x%10) * product;
        x /= 10;
        product *= p;
    }
    return ans;
}

void from_D(int x, int p) // 将十进制数x转换为p进制
{
    do
    {
        z[num++] = x % p;
        x /= p;
    } while (x != 0);
}

int reverse(int n) // 数的反转
{
    int ans = 0;
    while(n != 0)
    {
        ans = ans*10 + n%10;
        n /= 10;
    }
    return ans;
}

bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    int sqr = (int)sqrt(1.0*n);
    for(int i=2; i<=sqr; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, d;
    while(scanf("%d", &n)!=EOF)
    {   
        if(n < 0)
        {
            break;
        }
        scanf("%d", &d);
        memset(z, 0, sizeof(z));
        num = 0;
        if(d == 10)
        {
            int ans = reverse(n);
            //printf("###%d###\n", ans);
            if(isPrime(n) && isPrime(ans))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else 
        {
            from_D(n, d);
            int ans = 0;
            for(int i=0; i<num; i++)
            {
                ans = ans * d + z[i];
            }
            if(isPrime(n) && isPrime(ans))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}