// 进制转换

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

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
    int z[40], num = 0; // 数组z存放结果的每一位(由高位向低位输出)，num为位数
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


int main()
{
    printf("%d", reverse(34));

    return 0;
}