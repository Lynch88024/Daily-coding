#include <iostream>
#include <cstdio> 
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int sqr = (int)sqrt(1.0 * n);
    int len = 0, start = 0;
    for(int i=2; i<=sqr; i++)
    {
        int temp = 1;
        for(int j=i; ; j++)
        {
            temp *= j;
            if(n % temp != 0)
            {
                break;
            }
            else
            {
                if(j-i+1 > len)
                {
                    start = i;
                    len = j-i+1;
                }
            }
        }
    }
    if(len == 0)
    {
        printf("1\n");
        printf("%d", n);
    }
    else
    {
        printf("%d\n", len);
        for(int i=0; i<len; i++)
        {
            printf("%d", start+i);
            if(i != len-1)
            {
                printf("*");
            }
        }
    }
    

    return 0;
}

