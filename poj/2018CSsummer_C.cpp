#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
char map[maxn][maxn];
int num[maxn]; // 记录点数

int w, h; // w为列，h为行
int t = 0; // 记录点的个数s

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void DFS_1(int x, int y) // 在*中找连通X
{
    map[x][y] = '*'; // 找到X的时候直接将他变成*，这样就不用vis标记，同时也不会重复计算相邻的X
    for(int i=0; i<4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=h || xx<0 || yy>=w || yy<0 || map[xx][yy]=='*')
        {
            continue; 
        }
        if(map[xx][yy] == 'X')
        {
            DFS_1(xx, yy);
        }
    }
}

void DFS_2(int x, int y) // 在.中找连通*
{
    map[x][y] = '.';
    for(int i=0; i<4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=h || xx<0 || yy>=w || yy<0 || map[xx][yy]=='.')
        {
            continue; 
        }
        if(map[xx][yy] == '*')
        {
            DFS_2(xx, yy);
        }
        if(map[xx][yy] == 'X')
        {
            DFS_1(xx, yy);
            num[t]++; // 第t连通块的点数+1
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int icase = 1;
    while(scanf("%d %d", &w, &h) != EOF)
    {
        if(w==0 && h==0)
        {
            break;
        }
        t = 0; // 每次都要将上次的计数值清零
        memset(map, '.', sizeof(map));
        memset(num, 0, sizeof(num));

        for(int i=0; i<h; i++)
        {
            getchar(); // 吸收上一行的回车符
            for(int j=0; j<w; j++)
            {
                scanf("%c", &map[i][j]);
            }
        }
        for(int x=0; x<h; x++)
        {
            for(int y=0; y<w; y++)
            {
                if(map[x][y] == '*')
                {
                    DFS_2(x, y);
                    t++; // 下一个'*'连通块
                }
            }
        }
        sort(num, num+t); // 从小到大排序
        printf("Throw %d\n", icase++); 
        for(int i=0; i<t; i++)
        {
            printf("%d", num[i]);
            if(i != t-1)
            {
                printf(" ");
            }
            else 
            {
                printf("\n");
            }
        }
    }
    fclose(stdin);

    return 0;
}