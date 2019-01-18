#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath>
using namespace std;

const int M = 70;

int main()
{
    char s[2][M];
    char p[2][M];
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    scanf("%s", p[0]);
    scanf("%s", p[1]);
    int len_s0 = strlen(s[0]);
    int len_s1 = strlen(s[1]);
    int len_p0 = strlen(p[0]);
    int len_p1 = strlen(p[1]);
    int len_s, len_p = 0;
    if(len_s0 > len_s1)
        len_s = len_s1;
    else
        len_s = len_s0;
    if(len_p0 > len_p1)
        len_p = len_p1;
    else
        len_p = len_p0;

    char data[10][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int flag = 0;
    for(int i=0; i<len_s; i++)
    {
        if((s[0][i]==s[1][i])&&((s[0][i]>='A')&&(s[0][i]<='G'))&&(flag==0))
        {
            flag = 1;
            printf("%s ", data[s[0][i]-'A']);
            continue;
        }
        if((s[0][i]==s[1][i])&&(((s[0][i]>='A')&&(s[0][i]<='N'))||((s[0][i]>='0')&&(s[0][i]<='9')))&&(flag==1))
        {
            if((s[0][i]>='0')&&(s[0][i]<='9'))
            {
                printf("%02d:", s[0][i]-'0');
            }
            else 
            {
                printf("%d:", s[0][i]-'A'+10);
            }    
            break;
        }
    }
    for(int i=0; i<len_p; i++)
    {
        if((p[0][i]==p[1][i])&&(((p[0][i]>='A')&&(p[0][i]<='Z'))||((p[0][i]>='a')&&(p[0][i]<='z'))))
        {
            printf("%02d", i);
            break;
        }
    }

    return 0;
}