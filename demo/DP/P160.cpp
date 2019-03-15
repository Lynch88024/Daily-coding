// 素数表

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 101;
int prime[maxn]; // 素数表
int prime_num = 0; // 素数个数
bool is_prime[maxn]; // 某个数是否为素数

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

void find_prime() // 求素数表
{
    for(int i=1; i<maxn; i++)
    {
        if(isPrime(i) == true)
        {
            prime[prime_num++] = i;
            is_prime[i] = true; 
        }
    }
}

void find_prime_nb() // 埃氏筛法
{
    for(int i=0; i<maxn; i++)
    {
        is_prime[i] = true;
    }
    for(int i=2; i<maxn; i++)
    {
        if(is_prime[i] == true)
        {
            prime[prime_num++] = i;
            for(int j=i+i; j<maxn; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    find_prime_nb();
    for(int i=0; i<prime_num; i++)
    {
        printf("%d ", prime[i]);
    }

    return 0;
}