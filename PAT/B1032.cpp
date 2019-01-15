#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;

const int M = 100010;
int school[M] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    int id, score;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &id, &score);
        school[id] += score;
    }

    int max = 1;
    for(int i=1; i<=n; i++)
    {
        if(school[i] > school[max])
        {
            max = i;
        }
    }
    printf("%d %d\n", max, school[max]);

    return 0;
}