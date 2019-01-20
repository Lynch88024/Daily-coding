#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
int hashtable[N] = {0};

bool cmp(int a, int b);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int num = 0;
    int store[n] = {0};
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        store[i] = num;
        while(num != 1)
        {
            if(num%2 == 0)
            {
                num = num / 2;
            }
            else
            {
                num = (3*num+1) / 2;
            }
            hashtable[num]++;
        }
    }
    sort(store, store+n, cmp);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(hashtable[store[i]] == 0)
        {
            cnt++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(hashtable[store[i]] == 0)
        {
            cnt--;
            printf("%d", store[i]);
            if(cnt != 0)
                printf(" ");
        }
    }

    return 0;
}

bool cmp(int a, int b)
{
    return a > b;
}