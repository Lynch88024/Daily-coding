#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int x;
    int y;
};

const int maxn = 110;
int map[maxn][maxn] = {0};
bool vis[maxn][maxn] = {false};
int dx[2] = {0, 1};
int dy[2] = {1, 0};
queue<node> q;

int row, col;

bool judge(int x, int y)
{
    if(x<0 || x>=row || y<0 || y>=col)
    {
        return false;
    }
    if(vis[x][y] == true)
    {
        return false;
    }
    return true;
}

void BFS(int x, int y)
{
    node start;
    start.x = x;
    start.y = y;
    q.push(start);
    vis[x][y] = true;
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        printf("%d\n", map[front.x][front.y]);
        if(front.x==row-1 && front.y==col-1)
        {
            return ;
        }
        for(int i=0; i<2; i++)
        {
            int xx = front.x + dx[i];
            int yy = front.y + dy[i];
            if(judge(xx, yy) == true)
            {
                node temp;
                temp.x = xx;
                temp.y = yy;
                q.push(temp);
                vis[xx][yy] = true;
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &row, &col);
    for(int x=0; x<row; x++)
    {
        for(int y=0; y<col; y++)
        {
            scanf("%d", &map[x][y]);
        }
    }
    BFS(0, 0);
    // fclose(stdin);

    return 0;
}