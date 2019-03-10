// 带层号的BFS

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000;

struct Node
{
    int v;
    int layer;
};

int n;
vector<Node> Adj[MAXV];  // 邻接表
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};

void BFS(int u)
{
    queue<Node> q;
    Node start;
    start.v = u;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty())
    {
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i=0; i<Adj[u].size(); i++)
        {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if(inq[next.v] == false)
            {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}