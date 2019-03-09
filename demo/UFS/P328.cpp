// 并查集

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;
int father[N];

// 初始化
void init()
{
    for(int i=1; i<=N; i++)
    {
        father[i] = i;
    }
}

// 查找根节点
int findFather(int x)
{
    while(x != father[x])
    {
        x = father[x];
    }

    return x;
}

// 合并
void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
    {
        father[faA] = faB;
    }
}