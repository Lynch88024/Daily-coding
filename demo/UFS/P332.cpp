#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 105;
int father[maxn];
int flag[maxn];

void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        father[i] = i; 
        flag[i] = 0;
    }
}

int findFather(int x)
{
    // int a = x;
    while(x != father[x])
    {
        x = father[x];
    }
    // while(a != father[a])
    // {
    //     int z = a;
    //     a = father[a];
    //     father[z] = x;
    // }

    return x;
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) // 不在同一集中
    {
        father[faA] = faB;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    init(n); // 初始化
    int temp1, temp2;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        Union(temp1, temp2);
    }
    for(int i=1; i<=n; i++)
    {
        flag[findFather(i)] = 1; 
    }
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        cnt += flag[i];
    }
    printf("%d\n", cnt);

    return 0;
}