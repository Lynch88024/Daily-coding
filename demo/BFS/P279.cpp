#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 105;

struct node
{
    int x;
    int y;
    int step;
}Node, S, T;

int n, m;
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

bool judge(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return false;
    }
    if(maze[x][y]=='*' || inq[x][y]==true)
    {
        return false;
    }
    return true;
}

int BFS()
{
    queue<node> q;
    q.push(S);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        if(top.x==T.x && top.y==T.y)
        {
            return top.step;
        }
        for(int i=0; i<4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int x=0; x<n; x++)
    {
        getchar(); 
        for(int y=0; y<m; y++)
        {
            scanf("%c", &maze[x][y]);
        }
    }
    scanf("%d %d %d %d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d", BFS());

    return 0;
}

