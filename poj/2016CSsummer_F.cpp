/*
用getchar吸收回车，如果没计算地很精准，容易导致存储矩阵存储错误，因而对于字符存储，建议使用cin。
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int z, x, y;
    int layer;
}Start, End;

const int maxn = 35;
char map[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn] = {false};
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0}; 

int L, R, C;

void init()
{
    fill(map[0][0], map[0][0]+maxn*maxn*maxn, '#');
    fill(vis[0][0], vis[0][0]+maxn*maxn*maxn, false);
}

bool judge(int z, int x, int y)
{
    if(z<0 || z>=L || x<0 || x>=R || y<0 || y>=C)
    {
        return false;
    }
    if(vis[z][x][y]==true || map[z][x][y]=='#')
    {
        return false;
    }
    return true;
}

int BFS()
{
    queue<node> q;
    q.push(Start);
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        if(front.z==End.z && front.x==End.x && front.y==End.y)
        {
            return front.layer; // 到达终点
        }
        for(int i=0; i<6; i++)
        {
            int zz = front.z + dz[i];
            int xx = front.x + dx[i];
            int yy = front.y + dy[i];
            if(judge(zz, xx, yy) == true)
            {
                node temp;
                temp.z = zz;
                temp.x = xx;
                temp.y = yy;
                temp.layer = front.layer + 1;
                q.push(temp);
                vis[zz][xx][yy] = true;
            }
        }
    }
    return -1; // 无法到达终点
}

void print(int ans)
{
    if(ans == -1)
    {
        cout << "Trapped!" << endl;
    }
    else 
    {
        cout << "Escaped in " << ans << " minute(s)." << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    while(cin >> L >> R >> C)
    {
        if(L==0 && R==0 && C==0)
        {
            break;
        }
        init();
        for(int z=0; z<L; z++)
        {
            //getchar();
            for(int x=0; x<R; x++)
            {
                //getchar();
                for(int y=0; y<C; y++)
                {
                    char item;
                    cin >> item;
                    map[z][x][y] = item;
                    if(item == 'S')
                    {
                        Start.z = z;
                        Start.x = x;
                        Start.y = y;
                        Start.layer = 0;
                    }
                    if(item == 'E')
                    {
                        End.z = z;
                        End.x = x;
                        End.y = y;
                    }
                }
            }
        }
        int ans = BFS();
        print(ans);
    }
    fclose(stdin);

    return 0;
}