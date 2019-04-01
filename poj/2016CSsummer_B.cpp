#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 510;
char str[maxn];
char temp[maxn];

int main()
{
    gets(str);
    int len = strlen(str);
    int t = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] != ' ')
        {
            temp[t++] = str[i];
        }
        else 
        {
            for(int j=t-1; j>=0; j--)
            {
                cout << str[j];
                str[j] = '\0';
            }
            cout << " ";
            t = 0;
        }
    }
    if(t != 0)
    {
        for(int j=len-1; j>=len-t; j--)
        {
            cout << str[j];
            str[j] = '\0';
        }
        t = 0;
    }

    return 0;
}