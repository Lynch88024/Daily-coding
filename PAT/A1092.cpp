#include <iostream> 
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 1010;
int hashtable1[128] = {0};
int hashtable2[128] = {0};

int main()
{
    char s1[M];
    char s2[M];
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0; i<len1; i++)
    {
        hashtable1[s1[i]]++;
    }
    for(int i=0; i<len2; i++)
    {
        hashtable2[s2[i]]++;
    }
    int less, more = 0;
    for(int i=0; i<128; i++)
    {
        int dis = abs(hashtable1[i] - hashtable2[i]);
        if(hashtable1[i] < hashtable2[i])
        {
            less += dis;
        }
        if(hashtable1[i] > hashtable2[i])
        {
            more += dis;
        }
    }
    if(less > 0)
    {
        printf("No %d", less);
    }
    else
    {
        printf("Yes %d", more);
    }

    return 0;
}