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

bign reverse(bign a)
{
    bign b;
    b.len = a.len;
    for(int i=0; i<a.len; i++)
    {
        b.d[i] = a.d[a.len-1-i]; 
    }
    return b;
}

bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for(int i=0; i<max(a.len, b.len); i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
    {
        c.d[c.len++] = carry;
    }
    return c;
}

bool judge(bign a)
{
    for(int i=0; i<a.len/2; i++)
    {
        if(a.d[i] != a.d[a.len-1-i])
        {
            return false;
        }
    }
    return true;
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
    char str[maxn];
    int k;
    scanf("%s %d", str, &k); 
    bign a = change(str);

    int i;
    for(i=0; i<k; i++)
    {
        if(judge(a) == true)
        {
            print(a);
            printf("\n%d", i);
            break;
        }
        else 
        {
            bign b = reverse(a);
            a = add(a, b);
        }
    }
    if(i == k)
    {
        print(a);
        printf("\n%d", k);
    }

    return 0;
}