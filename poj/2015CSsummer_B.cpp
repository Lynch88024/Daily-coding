#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 210;
char str[maxn];
bool flag = true;

int main()
{
    gets(str);
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i] != ' ')
        {
            printf("%c", str[i]);
            flag = true;
        }
        else 
        {
            if(flag == true)
            {
                printf(" ");
                flag = false;
            }
            continue;
        }
    }

    return 0;
}