#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 110;
int map[maxn][maxn] = {0};

int row, col;

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &row, &col);
    for(int x=0; x<row; x++)
    {
        for(int y=0; y<col; y++)
        {
            scanf("%d", &map[x][y]);
        }
    }
    for(int sum=0; sum<=row+col-2; sum++)
    {
        for(int x=0; x<=sum&&x<row; x++)
        {
            if(sum-x>=0 && sum-x<col)
            {
                printf("%d\n", map[x][sum-x]);
            }
        }
    }
    fclose(stdin);

    return 0;
}