#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;

const int N = 100010;

struct student 
{
    int id;
    int score_A;
    int score_B;
    int score;
}stu[5][N], test[N];

bool cmp(student a, student b);

int main()
{
    int n, L, H = 0;
    scanf("%d %d %d", &n, &L, &H);
    int cnt[5] = {0};
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &test[i].id, &test[i].score_A, &test[i].score_B);
        test[i].score = test[i].score_A + test[i].score_B;
        if((test[i].score_A>=L) && (test[i].score_B>=L))
        {
            if((test[i].score_A>=H) && (test[i].score_B>=H))
            {
                stu[1][cnt[1]++] = test[i];
            }
            else if((test[i].score_A>=H) && (test[i].score_B<H))
            {
                stu[2][cnt[2]++] = test[i];
            }
            else if((test[i].score_A<H) && (test[i].score_B<H) && (test[i].score_A>=test[i].score_B))
            {
                stu[3][cnt[3]++] = test[i];
            }
            else
            {
                stu[4][cnt[4]++] = test[i];
            }
        }      
    }
    for(int i=1; i<=4; i++)
    {
        sort(stu[i], stu[i]+cnt[i], cmp);
        for(int j=0; j<cnt[i]; j++)
        {
            stu[0][cnt[0]++] = stu[i][j];
        }
    }
    printf("%d\n", cnt[0]);
    for(int i=0; i<cnt[0]; i++)
    {
        printf("%d %d %d\n", stu[0][i].id, stu[0][i].score_A, stu[0][i].score_B);
    }

    return 0;
}

bool cmp(student a, student b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else if(a.score_A != b.score_A)
        return a.score_A > b.score_A;
    else
        return a.id < b.id;
}