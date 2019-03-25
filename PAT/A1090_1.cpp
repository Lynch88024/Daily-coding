#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node
{
    vector<int> child;
}node[maxn];

int n, layer_max = 0, layer_cnt = 0;

void DFS(int index, int depth)
{
    if(node[index].child.size() == 0)
    {
        if(depth > layer_max)
        {
            layer_max = depth;
            layer_cnt = 1;
        }
        else if(depth == layer_max)
        {
            layer_cnt++;
        }
        return ;
    }
    for(int i=0; i<node[index].child.size(); i++)
    {
        DFS(node[index].child[i], depth+1); 
    }
}

int main()
{
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
    DFS(root, 0);
    double price = p * pow(1+r/100.0, layer_max);
    printf("%.2lf %d", price, layer_cnt);

    return 0;
}