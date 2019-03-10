// 图的遍历  邻接表

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000;

int n;
vector<int> Adj[MAXV];  // 邻接表
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};

void DFS(int u, int depth)
{
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if(vis[v] == false)
        {
            DFS(v, depth+1);
        }
    }
}

void DFSTrave()
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
        for(int i=0; i<Adj[u].size(); i++)
        {
            int v = Adj[u][i];
            if(inq[v] == false)
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