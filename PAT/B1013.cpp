#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int prime[maxn];
int num = 0;

bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    int sqr = (int)sqrt(1.0*n);
    for(int i=2; i<=sqr; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

void find_prime(int n)
{
    int i = 1;
    while(num <= n)
    {
        if(isPrime(i) == true)
        {
            prime[++num] = i;
        }
        i++;
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    find_prime(n); 
    int cnt = 0;
    for(int i=m; i<=n; i++)
    {
        printf("%d", prime[i]);
        cnt++;
        if(cnt%10 != 0 && i!=n)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}