#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;

int get_num(int a[]);
bool cmp(int a, int b);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int a[4] = {0};
    do
    {
        int i = 0;
        while(n != 0)
        {
            a[i++] = n % 10;
            n /= 10;
        }
        {
            sort(a, a+4);
            int num1 = get_num(a);
            sort(a, a+4, cmp);
            int num2 = get_num(a);
            n = num2 - num1;
            printf("%04d - %04d = %04d\n", num2, num1, n);       
        }
    }while(n != 6174 && n != 0);

    return 0;
}

int get_num(int a[])
{
    int sum = 0;
    for(int i=0; i<4; i++)
    {
        sum = sum * 10 + a[i];
    }
    return sum;
}

bool cmp(int a, int b)
{
    return a > b;
}