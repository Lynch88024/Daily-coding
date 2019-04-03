#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;
int G[30][30];
int d[30];
bool vis[30] = {false};

void init()
{
    fill(G[0], G[0]+30*30, INF);
    fill(d, d+30, INF);
    fill(vis, vis+30, false);
}

int prime(int n) // 默认0号结点为初始结点，函数返回最小生成树的边权和
{
    d[0] = 0; // 默认从0开始，也可以换成其他结点
    int ans = 0; // 存放边权和
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
        for(int v=0; v<n; v++)
        {
            if(vis[v]==false && G[u][v]!=INF && G[u][v]<d[v])
            {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
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
                        char temp;
                        int weight;
                        getchar();
                        scanf("%c %d", &temp, &weight);
                        G[start-'A'][temp-'A'] = G[temp-'A'][start-'A'] = weight;
                    }
                }
            }
            int ans = prime(n);
            printf("%d\n", ans);
        } 
    }
    fclose(stdin);

    return 0;
}