#include <iostream> 
#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int K = 305;

struct student 
{
    char id[15];
    int score;
    int location;
    int rank_final;
    int rank_local;
}stu[N*K], test[K];

bool cmp(student a, student b);

int main()
{
    int n = 0;
    //int number = 0;
    int t = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int k = 0;
        scanf("%d", &k);
        //number += k;
        for(int j=0; j<k; j++)
        {
            scanf("%s %d", test[j].id, &test[j].score);
            test[j].location = i;
        }
        sort(test, test+k, cmp);
        test[0].rank_local = 1;
        for(int i=1; i<k; i++)
        {
            if(test[i].score == test[i-1].score)
            {
                test[i].rank_local = test[i-1].rank_local;
            }
            else
            {
                test[i].rank_local = i + 1;
            }
        }
        for(int i=0; i<k; i++)
        {
            stu[t++] = test[i];
        }
    }
    sort(stu, stu+t, cmp);
    stu[0].rank_final = 1;
    for(int i=1; i<t; i++)
    {
        if(stu[i].score == stu[i-1].score)
        {
            stu[i].rank_final = stu[i-1].rank_final;
        }
        else
        {
            stu[i].rank_final = i + 1;
        }
    }
    printf("%d\n", t);
    for(int i=0; i<t; i++)
    {
        printf("%s %d %d %d\n", stu[i].id, stu[i].rank_final, stu[i].location, stu[i].rank_local);
    }

    return 0;
}

bool cmp(student a, student b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}