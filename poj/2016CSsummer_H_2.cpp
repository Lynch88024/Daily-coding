#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30; // 结点的最大数量
const int maxr = 105; // 边的最大数量

struct edge
{
    int u, v; // 边的两个端点的编号
    int cost; // 边权
}E[maxr];

int father[maxn]; // 并查集使用的父亲结点

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

int findFather(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }
    while(a != father[a])
    {
        int z = a;
        a = father[a]; // 更新a
        father[z] = x; // 将所有结点的父节点改为x
    }
    return x;
}

int krusral(int n, int m) // n为结点数，m为边数
{
    int ans = 0; // 边长和
    int num_edge = 0; // 选取边的个数
    for(int i=0; i<maxn; i++) // 初始化并查集
    {
        father[i] = i;
    }
    sort(E, E+m, cmp); // 将边长从小到大排序
    for(int i=0; i<m; i++)
    {
        int father_u = findFather(E[i].u);
        int father_v = findFather(E[i].v);
        if(father_u != father_v)
        {
            father[father_v] = father_u; // 合并并查集
            ans += E[i].cost;
            num_edge++;
            if(num_edge == n-1) // 记录的边==结点数-1
            {
                break;
            }
        }
    }
    if(num_edge != n-1)
    {
        return -1; // 图不连通
    }
    else 
    {
        return ans; // 返回最小生成树的边权和
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n)!=EOF && n!=0)
    {
        int k = 0; // 边的计数器
        for(int i=0; i<n-1; i++)
        {
            char start;
            int num;
            getchar();
            scanf("%c %d", &start, &num);
                //sum += num; 
            if(num != 0)
            {
                for(int j=0; j<num; j++)
                {
                    char temp;
                    int weight;
                    getchar();
                    scanf("%c %d", &temp, &weight);
                    E[k].u = start - 'A';
                    E[k].v = temp - 'A';
                    E[k++].cost = weight;
                }
            }
        }
        int ans = 0;
        ans = krusral(n, k);
        printf("%d\n", ans);
    }
    fclose(stdin);

    return 0;
}