#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 10010;
char s[M];
char x[M];

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    int e = 0;
    for(int i=0; i<len; i++)
    {
        if(s[i] == 'E')
        {
            e = i;
        }
    }
    if(s[0] == '-')
    {
        printf("-");
    }

    int eof = 0;
    for(int i=e+2; i<len; i++)
    {
        eof = eof * 10 + (s[i]-'0');
    }
    
    if(eof == 0)
    {
        for(int i=1; i<e; i++)
        {
            printf("%c", s[i]);
        }
    }
    else
    {
        if(s[e+1] == '-')
        {
            printf("0.");
            
            for(int i=2; i<2+eof-1; i++)
            {
                printf("0");
            }
            printf("%c", s[1]);
            for(int i=3; i<e; i++)
            {
                printf("%c", s[i]);
            }
        }
        else
        {
            printf("%c", s[1]);
            if(eof < e-2-1)
            {
                for(int i=3; i<3+eof; i++)
                {
                    printf("%c", s[i]); 
                }
                printf(".");
                for(int i=3+eof; i<e; i++)
                {
                    printf("%c", s[i]);
                }
            }
            else
            {
                for(int i=3; i<e; i++)
                {
                    printf("%c", s[i]);
                }
                for(int i=0; i<eof-(e-3); i++)
                {
                    printf("0");
                }
            }
        }
    }
    
    return 0;
}