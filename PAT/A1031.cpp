#include <iostream> 
#include <cstdio> 
#include <cstring>
using namespace std;

const int M = 1000000;
char s[M];

int main()
{
    scanf("%s", s);
    int N = strlen(s);
    int n1 = (N+2)/3;
    int n3 = n1; 
    int t = N+2-3*n1;
    int n2 = n1 + t;
    // cout << N << endl;
    // cout << n1 << endl;
    // cout << n2 << endl;
    // cout << n3 << endl;
    // cout << t << endl;
    for(int i=0; i<n1-1; i++)
    {
        printf("%c", s[i]);
        for(int j=0; j<n2-2; j++)
        {
            printf(" ");
        }
        printf("%c\n", s[N-1-i]);
    }
    for(int i=0; i<n2; i++)
    {
        printf("%c", s[n1-1+i]);
    }

    return 0;
}