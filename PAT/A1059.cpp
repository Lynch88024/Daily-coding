#include <iostream>
#include <cstdio>
#include <cmath> 
#include <algorithm>
using namespace std;

const int maxn = 100010;
bool is_prime[maxn];
int prime[maxn], num = 0;

struct factor
{
    int p;
    int k;
}fac[10];


void find_Prime()
{
    for(int i=2; i<maxn; i++)
    {
        if(is_prime[i] == true)
        {
            prime[num++] = i;
            for(int j=i+i; j<maxn; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<maxn; i++)
    {
        is_prime[i] = true;
    }
    if(n == 1)
    {
        printf("1=1");
    }
    else
    {
        printf("%d=", n);
        int cnt = 0;
        find_Prime();
        int sqr = (int)sqrt(1.0 * n);
        for(int i=0; i<num && prime[i]<=sqr; i++)
        {
            if(n % prime[i] == 0)
            {
                fac[cnt].p = prime[i];
                fac[cnt].k = 0;
                while(n % prime[i] == 0)
                {
                    fac[cnt].k++;
                    n /= prime[i];
                }
                cnt++;
            }
            if(n == 1)
            {
                break;
            }
        }
        if(n != 1)
        {
            fac[cnt].p = n;
            fac[cnt++].k = 1;
        }
        for(int i=0; i<cnt; i++)
        {
            if(fac[i].k == 1)
            {
                printf("%d", fac[i].p);
            }
            else
            {
                printf("%d^%d", fac[i].p, fac[i].k);
            }
            if(i != cnt-1)
            {
                printf("*");
            }
        }
    }
    

    return 0;
}