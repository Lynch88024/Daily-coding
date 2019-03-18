// 高精度整数

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign
{
    int d[1000];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) // 大整数存储
{
    bign a;
    a.len = strlen(str);
    for(int i=0; i<a.len; i++)
    {
        a.d[i] = str[a.len-i-1] - '0';
    }
    return a;
}

int compare(bign a, bign b) // 比较
{
    if(a.len > b.len)
    {
        return 1;
    }
    else if(a.len < b.len)
    {
        return -1;
    }
    else
    {
        for(int i=a.len-1; i>=0; i--)
        {
            if(a.d[i] > b.d[i])
            {
                return 1;
            }
            else if(a.d[i] < b.d[i])
            {
                return -1;
            }
        }
        return 0;
    }   
}