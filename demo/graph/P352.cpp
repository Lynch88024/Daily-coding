// 图的遍历  邻接矩阵

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000; 
const int INF = 1000000000;

int n;
int G[MAXV][MAXV];        // 邻接矩阵
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};

void DFS(int u, int depth)  // 遍历顶点u所在的连通子图
{
    vis[u] = true;
    for(int v=0; v<n; v++)
    {
        if(vis[v]==false && G[u][v]!=INF)
        {
            DFS(v, depth+1);
        }
    }
}

void DFSTrave()  // 遍历图
{
    for(int u=0; u<n; u++)
    {
        if(vis[u] == false)
        {
            DFS(u, 1);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++)
        {
            if(inq[v]==false && G[u][v]!=INF)
            {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave()
{
    for(int u=0; u<n; u++)
    {
        if(inq[u] == false)
        {
            BFS(u);
        }
    }
}

