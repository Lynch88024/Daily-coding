#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int hashtable[N];

void swap(int &a, int &b);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int cnt = 0;
    int count = 0;
    int start = 1;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        hashtable[a[i]] = i;
        if(hashtable[a[i]] != a[i])
        {
            cnt++;
        }
    }
    while(cnt != 0)
    {
        if(a[0] != 0)
        {
            swap(a[hashtable[0]], a[hashtable[hashtable[0]]]);
            swap(hashtable[0], hashtable[hashtable[0]]);
            cnt--;
            count++;
            if(a[0] == 0)
            {
                cnt--;
            }
        }
        else
        {
            for(int i=start; i<n; i++)
            {
                if(hashtable[a[i]] != a[i])
                {
                    swap(a[0], a[i]);
                    swap(hashtable[a[0]], hashtable[a[i]]);
                    cnt++;
                    count++;
                    start = i;
                    break;
                }
            }
        }
    }
    printf("%d", count);

    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}