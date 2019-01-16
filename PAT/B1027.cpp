#include <iostream>
#include <cstdio> 
#include <cmath> 
using namespace std;

int main()
{
    int n = 0;
    char c;
    scanf("%d %c", &n, &c);
    int k = (int)floor(sqrt((n+1)/2.0));
    int left = n-2*k*k+1;
    for(int i=k; i>0; i--)
    {
        for(int j=0; j<k-i; j++)
        {
            printf(" ");
        }
        for(int j=0; j<2*i-1; j++)
        {
            printf("%c", c);
        }
        // for(int j=0; j<k-i; j++)
        // {
        //     printf(" ");
        // }
        printf("\n");
    }
    for(int i=2; i<=k; i++)
    {
        for(int j=0; j<k-i; j++)
        {
            printf(" ");
        }
        for(int j=0; j<2*i-1; j++)
        {
            printf("%c", c);
        }
        // for(int j=0; j<k-i; j++)
        // {
        //     printf(" ");
        // }
        printf("\n");
    }
    printf("%d", left);

    return 0;
}