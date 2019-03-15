#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector> 
#include <algorithm>
using namespace std;

const int maxn = 10010;
int prime[maxn], prime_num = 0;
int hashtable[maxn] = {0};
int isprime[maxn];

vector<int> out;

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

void findPrime()
{
    for(int i=0; i<maxn; i++)
    {
        isprime[i] = true;
    }
    for(int i=2; i<maxn; i++)
    {
        if(isprime[i] == true)
        {
            prime[prime_num++] = i;
            for(int j=i+i; j<maxn; j+=i)
            {
                isprime[j] = false;
            }
        }
    }
}

int main()
{
    int size, n;
    scanf("%d %d", &size, &n); 
    findPrime();
    for(int i=0; i<prime_num; i++)
    {
        if(prime[i] >= size)
        {
            size = prime[i];
            break;
        }
    }
    //printf("!!%d!!", size);
    int key;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &key);
        int pos = key % size;
        
        if(hashtable[pos] == 0)
        {
            hashtable[pos] = 1;
            out.push_back(pos);
        }
        // else
        // {
        //     int k = 0;
        //     while(1)
        //     {
        //         k++;
        //         key += k * k;
        //         pos = key % size;
        //         if(k==size)
        //         {
        //             out.push_back(-1);
        //             break;
        //         }
        //         else if(hashtable[pos] == 0)
        //         {
        //             hashtable[pos] = 1;
        //             out.push_back(pos);
        //             break;
        //         }
        //     }   
        // }
        else
        {
            int step;
            for(step=1; step<size; step++)
            {
                pos = (key + step*step) % size;
                if(hashtable[pos] == 0)
                {
                    hashtable[pos] = 1;
                    out.push_back(pos);
                    break;
                }
            }
            if(step == size)
            {
                out.push_back(-1);
            }
        }
        
    }
    //printf("##%d##", out.size());
    for(int i=0; i<out.size(); i++)
    {
        if(out[i] >= 0)
        {
            printf("%d", out[i]);
        }
        else if(out[i] == -1)
        {
            printf("-");
        }
        if(i != out.size()-1)
        {
            printf(" ");
        }
    }

    return 0;
}