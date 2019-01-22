#include <iostream> 
#include <cstdio>
using namespace std;

const int N = 100010;
int sum[N];

int binary_search(int left, int right, int key);

int main()
{
    int n ,S = 0;
    int nearS = 100000010;
    scanf("%d %d", &n, &S);
    sum[0] = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    for(int i=1; i<=n; i++)
    {
        int j = binary_search(i, n+1, sum[i-1]+S);
        if(sum[j-1] == sum[i-1] + S)
        {
            nearS = S;
            break;
        }
        else if(j<=n && sum[j]-sum[i-1]<nearS)
        {
            nearS = sum[j] - sum[i-1];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int j = binary_search(i, n+1, sum[i-1]+nearS);
        if(sum[j-1] == sum[i-1] + nearS)
        {
            printf("%d-%d\n", i, j-1);
        }
    }
}

int binary_search(int left, int right, int key)
{
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(sum[mid] <= key)
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