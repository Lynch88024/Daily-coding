#include <iostream>
#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std; 

const int M = 2010;

struct student 
{
    int id;
    int score[4];
    int rank[4];
}stu[M];

bool cmp0(student a, student b);
bool cmp1(student a, student b);
bool cmp2(student a, student b);
bool cmp3(student a, student b);

int main()
{
    int n, m =0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3]; // 总分与均分在排序上等价
    }

    sort(stu, stu+n, cmp0);
    stu[0].rank[0] = 1;
    for(int i=1; i<n; i++)
    {
        if(stu[i].score[0] == stu[i-1].score[0])
        {
            stu[i].rank[0] = stu[i-1].rank[0];
        }
        else
        {
            stu[i].rank[0] = i + 1;
        }
    }

    sort(stu, stu+n, cmp1);
    stu[0].rank[1] = 1;
    for(int i=1; i<n; i++)
    {
        if(stu[i].score[1] == stu[i-1].score[1])
        {
            stu[i].rank[1] = stu[i-1].rank[1];
        }
        else
        {
            stu[i].rank[1] = i + 1;
        }
    }

    sort(stu, stu+n, cmp2);
    stu[0].rank[2] = 1;
    for(int i=1; i<n; i++)
    {
        if(stu[i].score[2] == stu[i-1].score[2])
        {
            stu[i].rank[2] = stu[i-1].rank[2];
        }
        else
        {
            stu[i].rank[2] = i + 1;
        }
    }

    sort(stu, stu+n, cmp3);
    stu[0].rank[3] = 1;
    for(int i=1; i<n; i++)
    {
        if(stu[i].score[3] == stu[i-1].score[3])
        {
            stu[i].rank[3] = stu[i-1].rank[3];
        }
        else
        {
            stu[i].rank[3] = i + 1;
        }
    }

    int idd = 0;
    char show[5] = {'A','C','M','E'};
    for(int i=0; i<m; i++)
    {
        int flag = 0;
        scanf("%d", &idd);
        for(int j=0; j<n; j++)
        {
            if(idd == stu[j].id)
            {
                flag = 1;
                int min = 0;
                for(int k=1; k<4; k++)
                {
                    if(stu[j].rank[k] < stu[j].rank[min])
                    {
                        min = k;
                    }
                }
                printf("%d %c\n", stu[j].rank[min], show[min]);
                break;
            }
        }
        if(flag == 0)
        {
            printf("N/A\n");
        }
    }

    return 0;
}

bool cmp0(student a, student b)
{
    if(a.score[0] != b.score[0])
        return a.score[0] > b.score[0];
    else
        return a.id < b.id;
}
bool cmp1(student a, student b)
{
    if(a.score[1] != b.score[1])
        return a.score[1] > b.score[1];
    else
        return a.id < b.id;
}
bool cmp2(student a, student b)
{
    if(a.score[2] != b.score[2])
        return a.score[2] > b.score[2];
    else
        return a.id < b.id;
}
bool cmp3(student a, student b)
{
    if(a.score[3] != b.score[3])
        return a.score[3] > b.score[3];
    else
        return a.id < b.id;
}