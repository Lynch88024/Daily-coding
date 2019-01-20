#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1010;
int hashtable[M] = {0};

int main()
{
    int n = 0;
    scanf("%d", &n);
    int team, player, score = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d-%d %d", &team, &player, &score);
        hashtable[team] += score;
    }
    int max = 0;
    for(int i=1; i<M; i++)
    {
        if(hashtable[i] > hashtable[max])
        {
            max = i;
        }
    }
    printf("%d %d\n", max, hashtable[max]);

    return 0;
}
