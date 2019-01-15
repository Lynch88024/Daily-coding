#include <iostream> 
#include <cstdio>
#include <cstring> 
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char temp[2][55];
    int num[2][55] = {0};
    for(int i=1; i<=13; i++)
    {
        temp[0][i] = 'S';
        temp[0][i+13] = 'H';
        temp[0][i+26] = 'C';
        temp[0][i+39] = 'D';
        num[0][i] = i;
        num[0][i+13] = i;
        num[0][i+26] = i;
        num[0][i+39] = i;
    }
    temp[0][53] = 'J';
    temp[0][54] = 'J';
    num[0][53] = 1;
    num[0][54] = 2;

    int sort[55] = {0};
    for(int i=1; i<=54; i++)
    {
        scanf("%d", &sort[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=54; j++)
        {
            temp[(i+1)%2][sort[j]] = temp[i%2][j];
            num[(i+1)%2][sort[j]] = num[i%2][j];
        }
    }

    for(int i=1; i<54; i++)
    {
        printf("%c%d ", temp[n%2][i], num[n%2][i]);
    }
    printf("%c%d", temp[n%2][54], num[n%2][54]);

    return 0;
}