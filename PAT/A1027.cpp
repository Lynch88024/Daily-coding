#include <iostream>
#include <cstdio> 
using namespace std;

int main()
{
    int x[5] = {0};
    scanf("%d %d %d", &x[0], &x[1], &x[2]);
    char change[5][5] = {{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'}};
    int num[5] = {0};
    char show[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    for(int i=0; i<3; i++)
    {
        do
        {
            change[i][num[i]++] = show[x[i]%13];
            x[i] /= 13;
        }while(x[i] != 0);
    }
    printf("#");
    for(int i=0; i<3; i++)
    {
        for(int j=1; j>=0; j--)
        {
            printf("%c", change[i][j]);
        }
    }

    return 0;
}