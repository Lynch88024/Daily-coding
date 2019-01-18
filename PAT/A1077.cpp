#include <iostream>
#include <cstdio> 
#include <cstring> 
using namespace std;

const int M = 265;
char line[110][M];

int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    char s[M];
    int len_min = M;
    for(int i=0; i<n; i++)
    {
        fgets(s, M, stdin);
        int len_s = strlen(s) - 1;  // 非常重要！！！！
        if(len_min > len_s)
        {
            len_min = len_s;
        }
        for(int j=0; j<len_s; j++)
        {
            line[i][j] = s[len_s-1-j];
        }
        line[i][len_s] = '\0';
    }
   
    int dot = len_min;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<dot; j++)
        {
            if(line[0][j] != line[i][j])
            {
                dot = j;
                //printf("%d %d %d***",i,j, dot);
                break;
            }
        }
    }
    if(dot == 0)
    {
        printf("nai");
    }
    else
    {
        for(int i=dot-1; i>=0; i--)
        {
            printf("%c", line[0][i]);
        }
    }

    //printf("\n\ndot = %d\n", dot);
    return 0;
}