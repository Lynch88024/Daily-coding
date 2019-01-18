#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a, b = 0;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    int x[10] = {0};
    if(sum == 0)
    {
        printf("0");
    }
    else if(sum > 0)
    {
        int i = 0;
        while(sum != 0)
        {
            x[i++] = sum % 1000;
            sum /= 1000;
        }
        printf("%d", x[i-1]);
        for(int j=i-2; j>=0; j--)
        {
            printf(",%03d", x[j]);
        }
    }
    else
    {
        int sum_abs = -sum;
        int i = 0;
        while(sum_abs > 0)
        {
            x[i++] = sum_abs % 1000;
            sum_abs /= 1000;
        }
        printf("-%d", x[i-1]);
        for(int j=i-2; j>=0; j--)
        {
            printf(",%03d", x[j]);
        }
    }

    return 0;
}