#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int prime[maxn];
bool flag[maxn];
int prime_num = 0; 

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

void findPrime(int n)
{ 
    for(int i=0; i<maxn; i++)
        flag[i] = true;
    for(int i=2; i<=n; i++)
    {
        if(flag[i] == true)
        {   
            prime[prime_num++] = i;
            for(int j=i+i; j<=n; j+=i)
            {
                flag[j] = false;
            }
        }
    }
    //printf("%d", prime_num);
}

int main()
{
    int n;
    scanf("%d", &n);
    findPrime(n);
    int cnt = 0;
    for(int i=0; i<prime_num-1; i++)
    {
        if(prime[i+1]-prime[i] == 2)
        {
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}