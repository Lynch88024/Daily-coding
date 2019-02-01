#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int a[n] = {0};
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] > a[i-1])
        {
            sum += (6 * (a[i]-a[i-1]) + 5);
        }
        else
        {
            sum += (4 * abs(a[i]-a[i-1]) + 5);
        }
        //printf("%d:%d\n",i, sum);
    }   
    printf("%d", sum);

    return 0;
}