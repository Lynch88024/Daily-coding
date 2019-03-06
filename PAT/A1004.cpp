#include <iostream>
#include <cstdio>
#include <queue>
#include <vector> 
using namespace std;

const int maxn = 105;
int layer[maxn] = {0};

struct Node
{
    int layer;
    bool flag;
    vector<int> child;
}node[maxn];

void levelorder(int root)
{
    queue<int> q;
    node[root].layer = 1;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0; i<node[now].child.size(); i++)
        {
            int child = node[now].child[i];
            node[child].layer = node[now].layer + 1;
            q.push(child);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        node[i].flag = true;
    }
    int par, num, child;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &par, &num);
        node[par].flag = false;
        for(int j=1; j<=num; j++)
        {
            scanf("%d", &child);
            node[par].child.push_back(child);
        }
    }
    levelorder(1);
    int layer_max = -1;
    for(int i=1; i<=n; i++)
    {
        if(node[i].flag == true)
        {
            layer[node[i].layer]++;
        }
        if(node[i].layer > layer_max)
        {
            layer_max = node[i].layer;
        }
    }
    for(int i=1; i<=layer_max; i++)
    {
        printf("%d", layer[i]);
        if(i != layer_max)
        {
            printf(" ");
        }
    }

    return 0;
}