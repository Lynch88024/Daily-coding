#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;

const int N = 1010;

struct student 
{
    char name[15];
    char id[15];
    int score;
}stu[N];

bool cmp(student a, student b);

int main()
{
    int n = 0;
    int left = 0;
    int right = 100;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
    }
    scanf("%d %d", &left, &right);
    sort(stu, stu+n, cmp);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if((stu[i].score>=left) && (stu[i].score<=right))
        {
            cnt++;
            printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    if(cnt == 0)
    {
        printf("NONE\n");
    }
 
    return 0;
}

bool cmp(student a, student b)
{
    return a.score > b.score;
}