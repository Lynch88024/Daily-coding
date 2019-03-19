#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

struct bign
{
    int d[maxn];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[])
{
    bign a;
    a.len = strlen(str); 
    for(int i=0; i<a.len; i++)
    {
        a.d[i] = str[a.len-1-i] - '0';
    }
    return a;
}

bign divide(bign a, int b, int &r)
{
    bign c;
    c.len = a.len;
    for(int i=a.len-1; i>=0; i--)
    {
        r = r*10 + a.d[i];
        if(r < b)
        {
            c.d[i] = 0;
        }
        else
        {
            c.d[i] = r / b;
            r %= b;
        }     
    }
    while(c.len-1>=1 && c.d[c.len-1]==0)
    {
        c.len--;
    }
    return c;
}

void print(bign a)
{
    for(int i=a.len-1; i>=0; i--)
    {
        printf("%d", a.d[i]); 
    }
}

int main()
{
    char a[maxn];
    int b, r=0;
    scanf("%s %d", a, &b);
    bign c = change(a);
    bign d = divide(c, b, r);
    print(d);
    printf(" %d", r);

    return 0;
}