#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 100010;
char s[M];
int num_P[M], num_T[M];
long long sum_P[M], sum_T[M];

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    int A = 0;
    for(int i=0; i<len; i++)
    {
        if(s[i] == 'A')
        {
            A++;
        }
        if(s[i] == 'P')
        {
            num_P[A]++;
        }
        if(s[i] == 'T')
        {
            num_T[A]++;
        }
    }
    sum_P[0] = num_P[0];
    for(int i=1; i<A; i++)
    {
        sum_P[i] = num_P[i] + sum_P[i-1];
    }
    sum_T[A] = num_T[A];
    for(int i=A-1; i>0; i--)
    {
        sum_T[i] = num_T[i] + sum_T[i+1];
    }
    long long sum = 0;
    for(int i=0; i<A; i++)
    {
        sum += sum_P[i] * sum_T[i+1];
    }
    printf("%d", sum%1000000007);

    return 0;
}