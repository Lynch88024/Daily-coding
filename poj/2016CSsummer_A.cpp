#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double n, ans;
    scanf("%lf", &n);
    if(n>=0.0 && n<5.0)
    {
        ans = 2.5 - n;
    }
    else if(n>=5.0 && n<10.0)
    {
        ans = 2.0 - 1.5*(n-3.0)*(n-3.0);
    }
    else if(n>=10.0 && n<20.0)
    {
        ans = n / 2.0 - 1.5;
    }
    printf("%.3f", ans);

    return 0;
}