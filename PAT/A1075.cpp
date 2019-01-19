#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <algorithm>
using namespace std;

const int M = 100010;

struct student 
{
    int id_user;
    int id_problem;
    int score[10] = {0};
    int perfect = 0;
    int flag = 0;
}stu[M];

int main()
{
    int n, k, m = 0;
    scanf("%d %d %d", &n, &k, &m);
    int full[10] = {0};
    for(int i=1; i<=k; i++)
    {
        scanf("%d", &full[i]);
    }
    int user, problem, score = 0;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &user, &problem, &score);
        stu[i].id_user = user;
        stu[i].id_problem = problem;
        stu[i].score[problem] = score;
        stu[i].flag = 1;
        if(score == full[problem])
        {
            stu[i].perfect++;
        }
    }


    return 0;
}