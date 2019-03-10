#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1010;
int vis[maxn] = {false};
vector<int> Adj[maxn]; 

int city, cnt = 0;

void DFS(int u)
{
    // if(u == city) // 待删除结点           // 对于删除的节点，当遍历到它的时候，可以直接return， 也可以判断使其不遍历到它。
    // {
    //     return ;
    // }
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if(v!=city && vis[v] == false)
        {
            DFS(v); 
        }
    } 
}

void DFSTrave(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(i != city && vis[i] == false)
        {
            cnt++;
            DFS(i);
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int temp1, temp2;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        Adj[temp1].push_back(temp2);
        Adj[temp2].push_back(temp1); 
    }
    for(int i=1; i<=k; i++)
    {
        cnt = 0;
        memset(vis, false, sizeof(vis)); // 每次循环后要恢复初始状态
        scanf("%d", &city);
        // vis[city] = true;
        DFSTrave(n);
        printf("%d\n", cnt-1);
    }

    return 0;
}