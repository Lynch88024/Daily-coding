#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100010;

struct Node
{
    int layer;
    vector<int> child;
}node[maxn];

void layerorder(int root)
{
    queue<int> q;
    node[root].layer = 0;
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
    int n;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    int temp, root;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        if(temp == -1)
        {
            root = i;
        }
        else
        {
            node[temp].child.push_back(i);
        }
    }
    layerorder(root);
    int layer_max = -1, layer_cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(node[i].layer > layer_max)
        {
            layer_max = node[i].layer;
            layer_cnt = 1;
        }
        else if(node[i].layer == layer_max)
        {
            layer_cnt++;
        }
    }
    double price = p * pow(1+r/100.0, layer_max);
    printf("%.2lf %d", price, layer_cnt);

    return 0;
}