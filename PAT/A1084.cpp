#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s1[85];
    char s2[85];
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dot = 0;
    int hashtable[128] = {0};
    for(int i=0; i<len1; i++)
    {
        char c1 = s1[i];
        if((c1>='a') && (c1<='z'))
        {
            c1 -= 32;
        } 
        int j = 0;
        for(j=0; j<len2; j++)
        {
            char c2 = s2[j];
            if((c2>='a') && (c2<='z'))
            {
                c2 -= 32;
            }
            if(c1 == c2)
            {
                break;
            }
        }
        if(j == len2)
        {
            if(hashtable[c1] == 0)
            {
                printf("%c", c1);
                hashtable[c1] = 1;
            }
        }
    }
    
    return 0;
}