/*
此时队列中的每个元素并不是都等价，由于希望最后到达终点的层次最小，所以每次从队列中希望取出层次最小的结点，因而可以想到用小顶堆的优先队列来解决。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int x, y;
    int layer;
}Start, End, Temp;

struct cmp
{
    bool operator() (node a, node b)
    {
        return a.x > b.x; // 小顶堆
    }
};

const int maxn = 310;
char map[maxn][maxn];
bool inq[maxn][maxn] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
priority_queue<node, vector<node>, cmp > q; // 小顶堆

int row, col;

void init()
{
    fill(inq[0], inq[0]+maxn*maxn, false);
    while(!q.empty()) // 优先队列不支持clear清空
    {
        q.pop();
    }
}

int judge(int x, int y)
{
    if(x<0 || x>=row || y<0 || y>=col)
    {
        return 0;
    }
    if(inq[x][y]==true || map[x][y]=='R' || map[x][y]=='S')
    {
        return 0;
    }
    if(map[x][y] == 'B')
    {
        return 2;
    }
    return 1;
}

int BFS()
{
    q.push(Start);
    inq[Start.x][Start.y] = true;
    while(!q.empty())
    {
        node front = q.top();
        q.pop();
        if(front.x==End.x && front.y==End.y) 
        {
            return front.layer; 
        }        
        for(int i=0; i<4; i++)
        {
            int xx = front.x + dx[i];
            int yy = front.y + dy[i];
            if(judge(xx, yy) != 0)
            {
                Temp.x = xx;
                Temp.y = yy;
                Temp.layer = front.layer + judge(xx, yy);
                q.push(Temp);
                inq[xx][yy] = true;
            }
        }
    }
    return -1;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    while(cin >> row >> col)
    {
        if(row==0 && col==0)
        {
            break;
        }
        init();
        for(int x=0; x<row; x++)
        {
            for(int y=0; y<col; y++)
            {
                cin >> map[x][y];
                if(map[x][y] == 'Y')
                {
                    Start.x = x;
                    Start.y = y;
                    Start.layer = 0;
                }
                if(map[x][y] == 'T')
                {
                    End.x = x;
                    End.y = y;
                }
            }
        }
        cout << BFS();
    } 
    // fclose(stdin);

    return 0;
}