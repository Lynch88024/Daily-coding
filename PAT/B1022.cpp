#include <iostream>
#include <cstdio> 
using namespace std;

int main()
{
    int a, b, d = 0;
    scanf("%d %d %d", &a, &b, &d);
    int sum = a + b;
    int num = 0;
    int change[100];
    do
    {
        change[num++] = sum % d;
        sum /= d;
    }while(sum != 0);
    for(int i=num-1; i>=0; i--)
    {
        printf("%d", change[i]);
    }

    return 0;
}