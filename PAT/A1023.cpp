#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 25;

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

bign multi(bign a, int b)
{
    bign c;
    int carry = 0;
    for(int i=0; i<a.len; i++)
    {
        int temp = a.d[i]*b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

void hash_(bign a, int hashtable[10])
{
    for(int i=0; i<10; i++)
    {
        hashtable[i] = 0; 
    }
    for(int i=0; i<a.len; i++)
    {
        hashtable[a.d[i]]++;
    }
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
    scanf("%s", str); 
    bign a = change(str);
    bign b = multi(a, 2); 
    int hashtable_1[10], hashtable_2[10];
    hash_(a, hashtable_1);
    hash_(b, hashtable_2);   
    //print(b);
    int i = 0;
    for(i=0; i<10; i++)
    {
        if(hashtable_1[i] != hashtable_2[i])
        {
            printf("No\n");
            print(b);
            break;
        }
    }
    if(i == 10)
    {
        printf("Yes\n");
        print(b);
    }

    return 0;
}