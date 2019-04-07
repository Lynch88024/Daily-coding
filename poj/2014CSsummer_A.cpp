#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int value[6] = {100, 50, 20, 10, 5, 1};

int main()
{
    int sum;
    scanf("%d", &sum);
    for(int i=0; i<6; i++)
    {
        int num = sum / value[i];
        printf("%d\n", num);
        sum -= value[i]*num;
    }

    return 0;
}