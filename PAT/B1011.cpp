#include <iostream> 
#include <stdio.h>
#include <string.h>
using namespace std;

const int M = 15;
char *judge[M];

int main()
{
    int T = 0;
    long long A, B, C;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        scanf("%ld %ld %ld", &A, &B, &C);
        if(A+B > C)
        {
            judge[i] = "true";
        }
        else
        {
            judge[i] = "false";
        }
    }

    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: %s\n", i, judge[i]);
    }
    
    return 0;
}