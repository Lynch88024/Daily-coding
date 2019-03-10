#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 10010;
vector<int> Adj[maxn];
vector<int> ans, temp;
bool vis[maxn] = {false};
int hashtable[maxn] = {0};
int layer[maxn];

int n, cnt = 0;

void DFS(int u)
{
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if(vis[v] == false)
        {
            DFS(v); 
        }
    }
}

void DFSTrave()
{
    for(int i=1; i<=n; i++)
    {
        if(vis[i] == false)
        {
            cnt++;
            DFS(i);
        }
    }
}

void levelorder(int root)
{
    queue<int> q;
    q.push(root);
    layer[root] = 1;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(int i=0; i<Adj[front].size(); i++)
        {
            int child = Adj[front][i];
            layer[child] = layer[front] + 1;
            q.push(child);
        }
    }
}

void store( vector<int> a )
{
    int max = -1;
    for(int i=1; i<=n; i++)
    {
        if(layer[i] > max)
        {
            max = layer[i];
            a.clear();
            a.push_back(i);
        }
        else if(layer[i] == max)
        {
            a.push_back(i); 
        }
    }
}



int main()
{
    scanf("%d", &n);
    if(n == 1)
    {
        printf("1");
        return 0;
    }
    int temp1, temp2;
    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        Adj[temp1].push_back(temp2);
        Adj[temp2].push_back(temp1);
        hashtable[temp1]++;
        hashtable[temp2]++;
    }
    DFSTrave();
    if(cnt > 1)
    {
        printf("Error: %d components", cnt);
    }
    // else
    // {
    //     levelorder(1);
    //     store(ans);
    //     memset(layer, 0, sizeof(layer));
    //     levelorder(ans[0]);
    //     store(temp);
    //     for(int i=0; i<temp.size(); i++)
    //     {
    //         ans.push_back(temp[i]);
    //     }
    //     sort(ans.begin(), ans.end());
    //     printf("%d\n", ans[0]);
    //     for(int i=1; i<ans.size(); i++)
    //     {
    //         if(ans[i] != ans[i-1])
    //         {
    //             printf("%d\n", ans[i]);
    //         }
    //     }
    // }
    
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(hashtable[i] == 1)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}