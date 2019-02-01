#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    double sum = 0.0;
    for(int i=1; i<=n; i++)
    {
        double num = 0.0;
        scanf("%lf", &num);
        sum += num * i * (n-i+1);
    }
    printf("%.2lf", sum);

    return 0;
}