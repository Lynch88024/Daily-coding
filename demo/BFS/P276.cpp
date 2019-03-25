#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;

struct node
{
    int x, y;
}Node;

int n, m;
int matrix[maxn][maxn];  
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y)
{
    if(x>=n || x<0 || y>=m || y<0)
    {
        return false;
    }
    if(matrix[x][y]==0 || inq[x][y]==true)
    {
        return false;
    }
    return true;
}

void DFS(int x, int y)
{
    if(judge(x, y) == false)
    {
        return ;
    }
    inq[x][y] = true;
    for(int i=0; i<4; i++)
    {
        int newX = x + X[i];
        int newY = y + Y[i];
        DFS(newX, newY);
    } 
}

void BFS(int x, int y)
{
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while(!Q.empty())
    {
        node top = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
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
        for(int y=0; y<m; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            if(matrix[x][y]==1 && inq[x][y]==false)
            {
                ans++;
                DFS(x, y);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

