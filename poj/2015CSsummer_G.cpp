#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 80;
const int INF = 0x3fffffff;

char map[maxn][maxn];
int vis[maxn][maxn]; // 1~4记录每个结点转弯状态,0表示该结点被访问过与否
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int w, h;
int route = 0; // 记录每条路径的转弯次数
int min_ = INF;
int y_s, x_s, y_e, x_e;

void init_1()
{
    fill(map[0], map[0]+maxn*maxn, ' ');
    fill(vis[0], vis[0]+maxn*maxn, 0);
}

void init_2()
{
    min_ = INF;
    route = 0;
}

void DFS(int x, int y)
{
    if(route > min_)
    {
        return ; // 拐的次数多于之前的最小值，直接退出
    }
    if(route<min_ && x==x_e && y==y_e)
    {
        min_ = route;
        return ;
    }
    for(int i=0; i<4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if((xx>=0 && xx<=h+1 && yy>=0 && yy<=w+1 && map[xx][yy]!='X' && vis[xx][yy]==0) || (xx==x_e && yy==y_e))
        {
            int flag = 0; // 回溯的标志
            vis[xx][yy] = i+1; // 搜索前进的方向
            if(vis[x][y] != vis[xx][yy]) // 方向不一致，存在转弯
            {
                route++;
                //cout << route << endl;
                flag = 1;
            }
            DFS(xx, yy);
            vis[xx][yy] = 0; // 回溯
            if(flag == 1)
            {
                route--;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int time = 1;
    while(cin >> w >> h)
    {
        getchar();
        if(w==0 && h==0)
        {
            break;
        }
        init_1();
        cout << "Board #" << time++ << ":" << endl;
        // 因为存储的矩阵中存在很多' '，如果以字符形式输入很容易输入错乱，因而最好使用gets，以行的形式输入。
        for(int i=1; i<=h; i++)
        {
            gets(map[i]);
            for(int j=w; j>=0; j--)
            {
                map[i][j+1] = map[i][j];
            }
            map[i][0] = ' ';
        }
        // for(int i=1; i<=h; i++)
        // {
        //     for(int j=1; j<=w; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int label = 1;
        while(cin >> y_s >> x_s >> y_e >> x_e)
        {
            if(y_s==0 && x_s==0 && y_e==0 && x_e==0)
            {
                cout << endl;
                break;
            }
            init_2();
            cout << "Pair " << label++ << ": ";
            DFS(x_s, y_s);
            if(min_ == INF)
            {
                cout << "impossible." << endl;
            }
            else 
            {
                cout << min_ << " segments." << endl;
            }
        }
    }
    fclose(stdin);

    return 0;
}