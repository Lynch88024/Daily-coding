#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 210;
const double INF = 1e30;

struct Node
{
    double x, y;
}node[maxn];

double map[maxn][maxn];
bool vis[maxn];
double d[maxn];
vector<int> s; 

double v1 = 10000.0 / 60.0;
double v2 = 40000.0 / 60.0;

void init()
{
    fill(map[0], map[0]+maxn*maxn, INF);
    fill(vis, vis+maxn, false);
    fill(d, d+maxn, INF);
    s.clear();
}

double dis1(Node a, Node b) // 步行时长
{
    double len = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    double dis = len / v1;
    return dis;
}

double dis2(Node a, Node b) // 地铁时长
{
    double len = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    double dis = len / v2;
    return dis;
}

void Dijkstra(int start, int n)
{
    d[start] = 0.0;
    for(int i=0; i<n; i++)
    {
        int u = -1;
        double min_ = INF;
        for(int j=0; j<n; j++)
        {
            if(vis[j]==false && d[j]<min_)
            {
                u = j;
                min_ = d[j];
            }
        }
        if(u == -1)
        {
            return ;
        }
        vis[u] = true;
        for(int v=0; v<n; v++)
        {
            if(vis[v]==false && map[u][v]!=INF && d[u]+map[u][v]<d[v])
            {
                d[v] = d[u] + map[u][v];
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%lf %lf %lf %lf", &node[0].x, &node[0].y, &node[1].x, &node[1].y);
    init();
    int cnt = 2;
    double x, y;
    while(scanf("%lf %lf", &x, &y) != EOF)
    {
        if(x!=-1 && y!=-1)
        {
            node[cnt].x = x;
            node[cnt].y = y;
            s.push_back(cnt);
            cnt++;
        }
        else 
        {
            for(int i=0; i<s.size()-1; i++)
            {
                map[s[i]][s[i+1]] = map[s[i+1]][s[i]] = dis2(node[s[i]], node[s[i+1]]);
            }
            s.clear();
        }
    }
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i == j)
            {
                map[i][j] = INF;
            }
            else 
            {
                map[i][j] = map[j][i] = min(map[i][j], dis1(node[i], node[j]));
            }
        }
    }
    Dijkstra(0, cnt);
    double max_ = 0.0;
    for(int i=0; i<cnt; i++)
    {
        if(d[i] > max_)
        {
            max_ = d[i];
        }
    }
    printf("%.0lf", max_);
    fclose(stdin);

    return 0;
}