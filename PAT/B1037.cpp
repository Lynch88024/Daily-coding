#include <iostream>
#include <cstdio> 
using namespace std;

int main()
{
    int a[5] = {0};
    int b[5] = {0};
    int c[5] = {0};
    scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1],&b[2]);
    int sum_a = 17*29*a[0] + 29*a[1] + a[2];
    int sum_b = 17*29*b[0] + 29*b[1] + b[2];
    int dis = sum_b - sum_a;
    c[0] = abs(dis) / (17*29);
    c[1] = abs(dis) % (17*29) / 29;
    c[2] = abs(dis) % 29;
    if(dis >= 0)
    {
        printf("%d.%d.%d", c[0], c[1], c[2]);
    }
    else
    {
        printf("-%d.%d.%d", c[0], c[1], c[2]);
    }

    return 0;
}