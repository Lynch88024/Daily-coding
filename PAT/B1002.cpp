#include <iostream> 
#include <cstdio> 
#include <cstring> 
using namespace std;

const int M = 110;

int main()
{
    char s[M];
    scanf("%s", s);
    int len = strlen(s);
    int sum = 0;
    char show[15][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    for(int i=0; i<len; i++)
    {
        sum += (s[i] - '0');
    }
    int a = sum / 100;
    int b = sum / 10 % 10;
    int c = sum % 10;
    if(a == 0)
    {
        if(b == 0)
        {
            printf("%s", show[c]);
        }
        else
        {
            printf("%s %s", show[b], show[c]);
        }
    }
    else
    {
        printf("%s %s %s", show[a], show[b], show[c]);
    }

    return 0;
}