#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int cmp[128];

void init()
{
    for(char i='0'; i<='9'; i++)
    {
        cmp[i] = i - '0';
    }
    for(char i='a'; i<='z'; i++)
    {
        cmp[i] = i - 'a' + 10;
    }
}

LL change_D(char a[], int radix)
{
    LL sum = 0;
    for(int i=0; i<strlen(a); i++)
    {
        sum = sum * radix + cmp[a[i]];
    }
    return sum;
}

int main()
{
    char N1[20], N2[20], temp[20];
    int tag, radix = 0;
    scanf("%s %s %d %d", N1, N2, &tag, &radix);
    if(tag == 2)
    {
        strcpy(temp, N1);
        strcpy(N1, N2);
        strcpy(N2, temp);
    }
    LL number1 = change_D(N1, 10);
    LL number2 = change_D(N2, 10);


    return 0;
}