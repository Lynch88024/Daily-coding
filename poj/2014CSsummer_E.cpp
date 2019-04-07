#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 200010;
int array[maxn], temp[maxn];
long long ans = 0;

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int pos = left;
    while(i<=mid && j<=right)
    {
        if(array[i] <= array[j])
        {
            temp[pos++] = array[i++];
        }
        else 
        {
            temp[pos++] = array[j++];
            ans += mid-i+1;
        }
    }
    while(i <= mid)
    {
        temp[pos++] = array[i++];
    }
    while(j <= right)
    {
        temp[pos++] = array[j++];
    }
    for(int i=left; i<=right; i++)
    {
        array[i] = temp[i];
    }
}

void mergesort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, mid, right);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n)!=EOF && n!=0)
    {
        ans = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &array[i]);
        }
        mergesort(0, n-1);
        printf("%lld\n", ans);
    }
    fclose(stdin);

    return 0;
}