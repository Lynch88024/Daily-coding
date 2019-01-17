#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    if(n >= 10)
    {
        int a = n / 100;
        int b = n % 100 / 10;
        int c = n % 10;
        for(int i=0; i<a; i++)
        {
            printf("B");
        }
        for(int i=0; i<b; i++)
        {
            printf("S");
        }
        for(int i=0; i<c; i++)
        {
            printf("%d", i+1);
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            printf("%d", i+1);
        }
    }
    
    return 0;
}