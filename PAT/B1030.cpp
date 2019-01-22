#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, p = 0;
    scanf("%d %d", &n, &p);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int i, j = 0;
    int cnt = 1;
    while(i<n && j<n)
    {
        while(j<n && a[j]<=(long long)a[i]*p)
        {
            cnt = max(cnt, j-i+1);
            j++;
        }
        i++;
    }
    printf("%d\n", cnt);

    return 0;
}