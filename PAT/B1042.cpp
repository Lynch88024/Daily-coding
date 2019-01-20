#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 1010;
int hashtable[128] = {0};

int main()
{
    char s[M];
    fgets(s, M, stdin);
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        if((s[i]>='A') && (s[i]<='Z'))
        {
            s[i] += 32;
        }
        hashtable[s[i]]++;
    }
    char max = 'a';
    for(char i='b'; i<='z'; i++)
    {
        if(hashtable[i] > hashtable[max])
        {
            max = i;
        }
    }
    printf("%c %d", max, hashtable[max]);

    return 0;
}