#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int n) // 判断素数
{
    if(n <= 1)
    {
        return false;
    }
    int sqr = (int)sqrt(n*1.0);
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
    int x, y;
    scanf("%d %d", &x, &y);
    if(y < x) // 题中没说x、y的大小关系
    {
        swap(x, y);
    }
    //printf("%d %d", x, y);
    int ans = 0;
    for(int i=x; i<=y; i++)
    {
        if(isPrime(i))
        {
            ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
