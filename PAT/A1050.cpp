#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

const int M = 10010;
int hashtable[128];

int main()
{
    char s1[M];
    char s2[M];
    fgets(s1, M, stdin);
    fgets(s2, M, stdin);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0; i<len1; i++)
    {
        hashtable[s1[i]]++;
    }
    for(int i=0; i<len2; i++)
    {
        hashtable[s2[i]] = 0;
    }
    for(int i=0; i<len1; i++)
    {
        if(hashtable[s1[i]] != 0)
        {
            printf("%c", s1[i]);
        }
    }

    return 0;
}