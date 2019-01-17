#include <iostream> 
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 1010;

int main()
{
    char s[M];
    scanf("%s", s);
    int len = strlen(s);
    int cnt[15] = {0};
    for(int i=0; i<len; i++)
    {
        cnt[s[i]-'0']++;
    }
    for(int i=0; i<=9; i++)
    {
        if(cnt[i] != 0)
        {
            printf("%d:%d\n", i, cnt[i]);
        }
    }

    return 0;
}