#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Node
{
    int weight;
    vector<int> child;
}node[maxn];

int n, m, S;
int path[maxn];
vector<int> route;

bool cmp(int a, int b)
{
    return node[a].weight > node[b].weight; 
}

void DFS(int index, int depth, int sum)
{
    if((sum>S) || (sum==S&&node[index].child.size()!=0))
    {
        return ;
    }
    if(sum==S && node[index].child.size()==0)
    {
        for(int i=0; i<route.size(); i++)
        {
            printf("%d", node[route[i]].weight);  
            if(i != route.size()-1)
            {
                printf(" ");
            }
            else 
            {
                printf("\n");
            }
        }
        return ;
    }
    for(int i=0; i<node[index].child.size(); i++)
    {
        int child = node[index].child[i];
        //path[depth] = child;
        route.push_back(child);
        DFS(child, depth+1, sum+node[child].weight);
        route.pop_back(); // 为了回溯
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &S);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &node[i].weight);
    }
    int father, child, num;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &father, &num);
        for(int j=0; j<num; j++)
        {
            scanf("%d", &child);
            node[father].child.push_back(child);
        }
        sort(node[father].child.begin(), node[father].child.end(), cmp);
    }
    path[0] = 0; // 当需要考虑根节点时，需要初始化
    route.push_back(0); // 初始化！！！！
    DFS(0, 1, node[0].weight);

    return 0;
}