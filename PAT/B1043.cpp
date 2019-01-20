#include <iostream> 
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 10010;
int hashtable[128] = {0};
char s[M];

int main()
{
    fgets(s, M, stdin);
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        hashtable[s[i]]++;
    }
    char show[10] = {'P','A','T','e','s','t'};
    int number[10] = {0};
    int sum = 0;
    for(int i=0; i<6; i++)
    {
        number[i] = hashtable[show[i]];
        sum += number[i];
    }
    while(sum > 0)
    {
        for(int i=0; i<6; i++)
        {
            if(number[i] > 0)
            {
                printf("%c", show[i]);
                number[i]--;
                sum--;
            }
        }
    }

    return 0;
}