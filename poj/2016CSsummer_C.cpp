#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 210;
char str[maxn];
char map[maxn][25];

int main()
{
    freopen("input.txt", "r", stdin);
    int col;
    scanf("%d", &col); // 列
    scanf("%s", str);
    int len = strlen(str);
    int row = len / col; // 行
    int num = 0; // 字符记录数量
    for(int i=0; i<row; i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<col; j++)
            {
                map[i][j] = str[num++];
            }
        }
        else 
        {
            for(int j=col-1; j>=0; j--)
            {
                map[i][j] = str[num++];
            }
        }
    }
    for(int j=0; j<col; j++)
    {
        for(int i=0; i<row; i++)
        {
            printf("%c", map[i][j]);
        }
    }
    fclose(stdin);

    return 0;
}