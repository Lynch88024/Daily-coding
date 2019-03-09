#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn];
int flag[maxn];
int course[maxn];

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
    while(x != father[x])
    {
        x = father[x];
    }

    return x;
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
    {
        father[faA] = faB;
    }
}

bool cmp(int a, int b)
{
    return a > b; 
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int num, temp;
    for(int i=1; i<=n; i++)
    {
        scanf("%d:", &num);
        for(int j=0; j<num; j++)
        {
            scanf("%d", &temp);
            if(course[temp] == 0)
            {
                course[temp] = i;
            }
            Union(i, findFather(course[temp]));
        }
    }

    for(int i=1; i<=n; i++)
    {
        flag[findFather(i)]++;
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(flag[i] != 0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    sort(flag+1, flag+1+n, cmp);
    for(int i=1; i<=ans; i++)
    {
        printf("%d", flag[i]);
        if(i != ans)
        {
            printf(" ");
        }
    }

    return 0;
}