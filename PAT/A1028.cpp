#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

struct student 
{
    int id;
    char name[10];
    int score;
}stu[N];

bool cmp1(student a, student b);
bool cmp2(student a, student b);
bool cmp3(student a, student b);

int main()
{
    int n, c = 0;
    scanf("%d %d", &n, &c);
    for(int i=0; i<n; i++)
    {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }

    if(c == 1)
    {
        sort(stu, stu+n, cmp1);
    }
    else if(c == 2)
    {
        sort(stu, stu+n, cmp2);
    }
    else if(c == 3)
    {
        sort(stu, stu+n, cmp3);
    }

    for(int i=0; i<n; i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }

    return 0;
}

bool cmp1(student a, student b)
{
    return a.id < b.id;
}

bool cmp2(student a, student b)
{
    if(strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else
        return a.id < b.id;
}

bool cmp3(student a, student b)
{
    if(a.score != b.score)
        return a.score < b.score;
    else
        return a.id < b.id;
}