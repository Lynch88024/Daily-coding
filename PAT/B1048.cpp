#include <iostream> 
#include <cstdio>
#include <cmath> 
#include <cstring> 
using namespace std;

const int M = 110;

int main()
{
    char s1[M];
    char s2[M];
    char a[M];
    char b[M];
    scanf("%s %s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1>len2 ? len1 : len2;
    if(len1 < len2)
    {
        int i = 0;
        for(i=0; i<len2-len1; i++)
        {
            a[i] = '0';
        }
        a[i] = '\0';
        strcat(a, s1);
        strcpy(b, s2);
    }
    else 
    {
        int i = 0;
        for(i=0; i<len1-len2; i++)
        {
            b[i] = '0';
        }
        b[i] = '\0';
        strcat(b, s2);
        strcpy(a, s1);
    }
    // printf("%s\n", a);
    // printf("%s\n", b);
    
    char show[15] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
    if(len%2 == 1)
    {
        int flag = 1;
        for(int i=0; i<len; i++)
        {
            if(flag == 1)
            {
                printf("%c", show[(a[i]-'0'+b[i]-'0')%13]);
                flag = 0;
            }
            else
            {
                if(b[i]-a[i] >= 0)
                {
                    printf("%c", b[i]-a[i]+'0');
                }
                else
                {
                    printf("%c", b[i]-a[i]+10+'0');
                }
                flag = 1;
            }
        }
    }
    else
    {
        int flag = 0;
        for(int i=0; i<len; i++)
        {
            if(flag == 0)
            {
                if(b[i]-a[i] >= 0)
                {
                    printf("%c", b[i]-a[i]+'0');
                }
                else
                {
                    printf("%c", b[i]-a[i]+10+'0');
                }
                flag = 1;
            }
            else
            {
                printf("%c", show[(a[i]-'0'+b[i]-'0')%13]);
                flag = 0;
            }
        }
    }

    return 0;
}