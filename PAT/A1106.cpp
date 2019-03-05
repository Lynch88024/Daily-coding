#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 100010;

struct Node
{
    int layer;
    bool flag;
    vector<int> child;
}node[maxn];

void levelorder(int root)
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
    for(int i=0; i<n; i++)
    {
        node[i].flag = false;
    }
    int num, temp;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        if(num == 0)
        {
            node[i].flag = true;
        }
        else
        {
            for(int j=0; j<num; j++)
            {   
                scanf("%d", &temp);
                node[i].child.push_back(temp);
            }
        }
    }
    levelorder(0);
    int layer_min = maxn, layer_cnt = 0; 
    for(int i=0; i<n; i++)
    {
        if(node[i].flag == true)
        {
            if(node[i].layer < layer_min)
            {
                layer_min = node[i].layer;
                layer_cnt = 1;
            }
            else if(node[i].layer == layer_min)
            {
                layer_cnt++;
            }
        }
    }
    double price = p * pow(1+r/100.0, layer_min);
    printf("%.4lf %d", price, layer_cnt);

    return 0;
}