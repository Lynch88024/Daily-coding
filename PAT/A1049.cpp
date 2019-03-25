#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int left, now, right;
    int a = 1, ans = 0;

    while(n/a != 0)
    {
        left = n / (a*10);
        now = n / a % 10;
        right = n % a;
        if(now < 1)
        {
            ans += left * a;
        }
        else if(now == 1)
        {
            ans += left * a + right + 1;
        }
        else
        {
            ans += (left+1) * a;
        }
        a *= 10;
    }
    printf("%d", ans);

    return 0;
}