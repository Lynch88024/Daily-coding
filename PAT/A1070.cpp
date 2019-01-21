#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;

struct yuebing
{
    double number;
    double total;
    double one;
}yue[N];

bool cmp(yuebing a, yuebing b);

int main()
{
    int n = 0;
    int d = 0;
    scanf("%d %d", &n, &d);
    double volum = (double)d;
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &yue[i].number);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &yue[i].total);
        yue[i].one = yue[i].total / yue[i].number;
    }
    sort(yue, yue+n, cmp);
    double sum = 0.0;
    for(int i=0; i<n; i++)
    {
        if(yue[i].number == volum)
        {   
            sum += yue[i].total;
            volum = 0.0;
            break;
        }
        else if(yue[i].number > volum)
        {
            sum += yue[i].one * volum;
            volum = 0.0;
            break;
        }
        else
        {
            sum += yue[i].total;
            volum -= yue[i].number;
        }
    }
    printf("%.2lf", sum);

    return 0;
}

bool cmp(yuebing a, yuebing b)
{
    return a.one > b.one;
}