#include <iostream>
#include <cstdio> 
using namespace std;

int main()
{
    long long a[5] = {0};
    long long b[5] = {0};
    long long c[5] = {0};
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a[0], &a[1], &a[2], &b[0], &b[1],&b[2]);
    long long sum_a = 17*29*a[0] + 29*a[1] + a[2];
    long long sum_b = 17*29*b[0] + 29*b[1] + b[2];
    long long sum = sum_b + sum_a;
    c[0] = sum / (17*29);
    c[1] = sum % (17*29) / 29;
    c[2] = sum % 29;
    printf("%lld.%lld.%lld", c[0], c[1], c[2]);
    
    return 0;
}