#include <iostream>
#include <stdio.h> 
using namespace std;

int main()
{
    int n = 0;
    int cnt = 0;
    // cin >> n;
    scanf("%d", &n);
    while( n!=1 )
    {
        cnt ++;
        if( n%2==0 ) 
        {
            n = n / 2;
        }
        else
        {
            n =  (3 * n + 1) / 2;
        }
    }
    // cout << n << endl;
    printf("%d\n", cnt);

    return 0;
}