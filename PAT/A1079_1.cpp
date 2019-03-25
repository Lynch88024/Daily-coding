#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node
{
    int data;
    int layer;
    vector<int> child;
}node[maxn];

int n;
double p, r;
double price = 0.0;

void DFS(int index, int depth)
{
    if(node[index].child.size() == 0)
    {
        price += p * node[index].data * pow(1+r/100.0, depth);
        return ;
    }
    for(int i=0; i<node[index].child.size(); i++)
    {
        DFS(node[index].child[i], depth+1);
    }
}

int main()
{
    scanf("%d %lf %lf", &n, &p, &r);
    int num, temp;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        if(num == 0)
        {
            scanf("%d", &node[i].data);
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
    DFS(0, 0);
    printf("%.1lf", price);

    return 0;
}