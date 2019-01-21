#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 100010;
int a[M], b[M];

bool cmp(int a, int b);

int main()
{
    int nc, np = 0;
    scanf("%d", &nc);
    for(int i=0; i<nc; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &np);
    for(int i=0; i<np; i++)
    {
        scanf("%d", &b[i]);
    }
    int min = nc<np ? nc: np;
    long long sum = 0;
    sort(a, a+nc, cmp);
    sort(b, b+np, cmp);
    for(int i=0; i<min; i++)
    {
        if((a[i]>0) && (b[i]>0))
        {
            sum += a[i] * b[i];
        }
        else
        {
            break;
        }
    }
    sort(a, a+nc);
    sort(b, b+np);
    for(int i=0; i<min; i++)
    {
        if((a[i]<0) && (b[i]<0))
        {
            sum += a[i] * b[i];
        }
        else
        {
            break;
        }
    }
    printf("%lld", sum);

    return 0;
}

bool cmp(int a, int b)
{
    return a > b;
}