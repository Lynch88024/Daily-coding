#include <iostream> 
#include <cstdio> 
#include <algorithm>
using namespace std;

const int N = 100010;
const int M = 10010;
int rank_arr[N];
int hashtable[M];

int main()
{
    int n = 0;
    scanf("%d", &n);
    int bet = 0;
    int r = 0;
    int list[n] = {0};
    for(int i=0; i<n; i++)
    {
        scanf("%d", &bet);
        if(hashtable[bet] == 0)
        {
            list[r++] = bet;
        }
        hashtable[bet]++;
    }
    int flag = 0;
    for(int i=0; i<r; i++)
    {
        if(hashtable[list[i]] == 1)
        {
            printf("%d", list[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("None");
    }

    return 0;
}