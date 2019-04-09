#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 25;
const int INF = 0x3fffffff;
int dis[maxn][maxn];

void init()
{
    fill(dis[0], dis[0]+maxn*maxn, INF);
}

void Floyd(int num)
{
    for(int k=1; k<=num; k++)
    {
        for(int i=1; i<=num; i++)
        {
            for(int j=1; j<=num; j++)
            {
                if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    init();
    for(int i=1; i<=19; i++)
    {
        int num;
        scanf("%d", &num);
        for(int j=0; j<num; j++)
        {
            int next;
            scanf("%d", &next);
            dis[i][next] = dis[next][i] = 1;
        }
    }
    Floyd(20); 
    int n, time = 1;;
    while(scanf("%d", &n) != EOF)
    {
        printf("Test Set #%d\n", time++);
        for(int i=0; i<n; i++)
        {
            int start_, end_;
            scanf("%d %d", &start_, &end_);
            printf("%d to %d: %d\n", start_, end_, dis[start_][end_]);
        }
    }  
    // fclose(stdin);

    return 0;
}