#include <iostream> 
#include <cstdio> 
#include <cstring> 
using namespace std;

const int M = 100010;

int main()
{
    char s1[128];
    char s2[M];
    int hashtable[128] = {0};
    fgets(s1, 128, stdin);
    fgets(s2, M, stdin);
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for(int i=0; i<len1; i++)
    {
        char c1 = s1[i];
        hashtable[c1] = 1;
        if((c1>='a') && (c1<='z'))
        {
            hashtable[c1-32] = 1;
        }
        else if((c1>='A') && (c1<='Z'))
        {
            hashtable[c1+32] = 1;
        }
    }
    if(hashtable['+'] == 1)
    {
        for(char i='A'; i<='Z'; i++)
        {
            hashtable[i] = 1;
        }
    }
    int cnt = 0;
    for(int i=0; i<len2; i++)
    {
        char c2 = s2[i];
        if(hashtable[c2] == 0)
        {
            printf("%c", c2);
            cnt++;
        }
    }
    if(cnt == 0)
    {
        printf("\n");
    }

    return 0;
}