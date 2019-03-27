#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int t[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int judge(int year)
{
    if((year%4==0 && year%100!=0) || (year%400==0))
    {
        return 1;
    }
    else 
        return 0;
}

int count_day(int year, int month, int day)
{
    int sum = 0;
    for(int i=1; i<year; i++)
    {
        sum += 365+judge(i);
    }
    if(judge(year) == 1)
    {
        for(int i=1; i<month; i++)
        {
            sum += t[i];
        }
    }
    else 
    {
        for(int i=1; i<month; i++)
        {
            sum += m[i];
        }
    }
    for(int i=1; i<=day; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int start_Y, start_M, start_D, end_Y, end_M, end_D;
    scanf("%d %d %d", &start_Y, &start_M, &start_D);
    scanf("%d %d %d", &end_Y, &end_M, &end_D);
    int sub = count_day(end_Y, end_M, end_D) - count_day(start_Y, start_M, start_D);
    printf("%d", sub);

    return 0;
}