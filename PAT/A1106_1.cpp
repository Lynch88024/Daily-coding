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
    vector<int> child;
}node[maxn];

int n;
double p, r;
int layer_min = maxn, layer_cnt = 0; 
double ans = 1e12;

void DFS(int index, int depth)
{
    if(node[index].child.size() == 0)
    {
        double price = p * pow(1+r/100.0, depth);
        if(price < ans)
        {
            ans = price;
            layer_cnt = 1;
        }
        else if(price == ans)
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
    scanf("%d %lf %lf", &n, &p, &r);
    int num, temp;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        if(num != 0)
        {
            for(int j=0; j<num; j++)
            {   
                scanf("%d", &temp);
                node[i].child.push_back(temp);
            }
        }
    }
    DFS(0, 0);
    printf("%.4lf %d", ans, layer_cnt);

    return 0;
}