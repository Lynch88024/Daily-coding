#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int v; // 结点编号
    int weight; // 边的权重
};

const int INF = 0x3fffffff;
vector<node> Adj[30]; // 邻接表
int d[30];
bool vis[30] = {false};

void init()
{
    fill(d, d+30, INF);
    fill(vis, vis+30, false);
    for(int i=0; i<30; i++)
    {
        Adj[i].clear(); // 清空vector
    }
}

int prime(int n)
{
    d[0] = 0;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int u = -1;
        int min = INF;
        for(int j=0; j<n; j++)
        {
            if(vis[j]==false && d[j]<min)
            {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
        {
            return -1;
        }
        vis[u] = true;
        ans += d[u];
        for(int j=0; j<Adj[u].size(); j++) // 更新和u直接相邻的未访问过的结点
        {
            int v = Adj[u][j].v; // u能直接到达的结点v
            if(vis[v]==false && Adj[u][j].weight<d[v])
            {
                d[v] = Adj[u][j].weight;
            }
        }
    }
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n != 0)
        {
            init(); // 初始化
            for(int i=0; i<n-1; i++)
            {
                char start;
                int num;
                getchar();
                scanf("%c %d", &start, &num);
                if(num != 0)
                {
                    for(int j=0; j<num; j++)
                    {
                        node dot1, dot2;
                        char temp;
                        int weight;
                        getchar();
                        scanf("%c %d", &temp, &weight);
                        dot1.v = temp - 'A';
                        dot1.weight = weight;
                        dot2.v = start - 'A';
                        dot2.weight = weight;
                        Adj[start-'A'].push_back(dot1);
                        Adj[temp-'A'].push_back(dot2); // 无向图！！！！！！
                    }
                }
            }
            int ans = prime(n);
            printf("%d\n", ans);
        }  
    }
    // fclose(stdin);

    return 0;
}