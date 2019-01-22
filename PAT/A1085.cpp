#include <iostream>
#include <cstdio> 
#include <algorithm> 
using namespace std;

const int N = 100010;
long long a[N];

int binary_search(long long a[], int left, int right, long long thr);

int main()
{
    int n, p = 0;
    scanf("%d %d", &n, &p);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int length = 1;

    // if(a[n-1] <= (long long)a[0]*p)
    // {
    //     length = n;
    // }
    // else
    // {
    //     for(int i=0; i<n; i++)
    //     {
    //         int out = binary_search(a, i+1, n-1, (long long)a[i]*p);
    //         length = max(length, out-i);
    //     }
    // }
    for(int i=0; i<n; i++)
    {
        int pos = binary_search(a, i+1, n, (long long)a[i]*p); // right设为n，如果n个元素全部满足条件，可以使left到达全部元素之后的位置n
        length = max(length, pos-i);
    }
    printf("%d", length);

    return 0;
}

int binary_search(long long a[], int left, int right, long long thr)
{
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(a[mid] <= thr)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    
    return left;
}