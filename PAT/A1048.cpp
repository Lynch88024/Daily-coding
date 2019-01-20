#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
int hashtable[N];

int main()
{
    int n, m, coin = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &coin);
        hashtable[coin]++;
    }
    int flag = 0;
    for(int i=0; i<m; i++)
    {
        if(hashtable[i]*hashtable[m-i] != 0)
        {
            if(i != m-i)
            {
                printf("%d %d", i, m-i);
                flag = 1;
                break;
            }
            else
            {
                if(hashtable[i] >= 2)
                {
                    printf("%d %d", i, i);
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("No Solution");
    }

    return 0;
}