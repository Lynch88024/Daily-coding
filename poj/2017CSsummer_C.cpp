#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int map[maxn][maxn] = {0};
int dx[4] = {0, 0, 1, -1}; // x y的邻接位置的4个方向
int dy[4] = {1, -1, 0, 0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for(int i=1; i<=n; i++) // 从1开始，给地图外框加一圈0，作为边界
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for(int x=1; x<=n; x++)
    {
        for(int y=1; y<=m; y++)
        {
            if(map[x][y] == 1)
            {
                for(int k=0; k<4; k++)
                {
                    if(map[x+dx[k]][y+dy[k]] == 0) // 陆地的四周有几面是海，该块陆地的周长就是几
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}