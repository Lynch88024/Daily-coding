#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int INF = 0x3fffffff;
int G[maxn][maxn] = {0}; // 图邻接矩阵
int d[maxn]; // 表示起点到各结点的最短距离
bool vis[maxn] = {false}; // 表示各结点被访问过与否

int n, start_, end_;

void init() // 初始化
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
            {
                G[i][j] = 0;
            }
            else 
            {
                G[i][j] = INF;
            }
        }
        // vis[i] = false;
        // d[i] = INF;
    }
}

// 初始化，n次循环，每次先确定与起点直接相连的距离最小结点u及其距离d[u]，再更新起点到其他结点v的距离d[v]
void Dijkstra(int start)
{
    for(int i=1; i<=n; i++)
    {
        d[i] = INF;
    }
    d[start] = 0; // 初始化，只有start结点可达
    for(int i=1; i<=n; i++)
    {
        int u = -1; // 距离最近的结点u
        int min = INF; // min存放最小的d[u]
        for(int j=1; j<=n; j++)
        {
            if(vis[j]==false && d[j]<min)
            {
                u = j; // 与起点直接相连的距离最小结点
                min = d[j]; 
            }
        }
        if(u == -1)
        {
            return ; // 说明剩下的未被访问过的结点都是与起点不可达的
        }
        vis[u] = true; // 设为已读
        for(int v=1; v<=n; v++)
        {
            // 此处d[u]有一个相加操作，所以在设置很大整数时不能设置为0x7fffffff，会导致溢出
            if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]) 
            {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &start_, &end_); 
    init(); // 初始化
    for(int i=1; i<=n; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j=0; j<k; j++)
        {
            int t;
            scanf("%d", &t);
            if(j == 0)
            {
                G[i][t] = 0; // 第一个连接点不需要旋转
            }
            else 
            {
                G[i][t] = 1; // 之后的每一次都需要旋转1次
            }
        }
    }
    Dijkstra(start_);
    if(d[end_] == INF)
    {
        printf("%d", -1);
    }
    else 
    {
        printf("%d", d[end_]);
    }
    // fclose(stdin);

    return 0;
}