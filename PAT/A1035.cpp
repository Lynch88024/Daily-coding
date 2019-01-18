#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

const int M = 1010;
char name[M][15];
char id[M][15];
int number[M] = {0};

int main()
{
    int n = 0;
    scanf("%d", &n);
    int cnt = 0;
    int t = 0;
    if(n == 0)
    {
        printf("There is 0 account and no account is modified");
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s %s", name[i], id[i]);
            int len = strlen(id[i]);
            int flag = 0;
            for(int j=0; j<len; j++)
            {
                if(id[i][j] == '1')
                {
                    id[i][j] = '@';
                    flag = 1;
                }
                if(id[i][j] == '0')
                {
                    id[i][j] = '%';
                    flag = 1;
                }
                if(id[i][j] == 'l')
                {
                    id[i][j] = 'L';
                    flag = 1;
                }
                if(id[i][j] == 'O')
                {
                    id[i][j] = 'o';
                    flag = 1;
                }           
            }
            if(flag == 1)
            {
                number[t++] = i;
                cnt++;
            }
        }
        if(cnt == 0)
        {
            if(n == 1)
                printf("There is 1 account and no account is modified");
            else
                printf("There are %d accounts and no account is modified", n);
        }
        else
        {
            printf("%d\n", cnt);
            for(int i=0; i<cnt; i++)
            {
                printf("%s %s\n", name[number[i]], id[number[i]]);
            }
        }
    }
    

    return 0;
}