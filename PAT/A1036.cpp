#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
    struct student 
    {
        char name[15];
        char gender;
        char id[15];
        int score;
    }stu, max, min;
    max.score = -1; 
    min.score = 101;
    int cnt_m, cnt_f = 0;
    int n = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %c %s %d", stu.name, &stu.gender, stu.id, &stu.score);
        if(stu.gender == 'M')
        {
            cnt_m++;
            if(stu.score < min.score)
            {
                min = stu;
            }
        }
        else
        {
            cnt_f++;
            if(stu.score > max.score)
            {
                max = stu;
            }
        }
    }
    if(cnt_f == 0)
    {
        printf("Absent\n");            
    }
    else
    {
        printf("%s %s\n", max.name, max.id);
    }
    if(cnt_m == 0)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", min.name, min.id);
    }
    if(cnt_f*cnt_m == 0)
    {
        printf("NA\n");
    }
    else
    {
        printf("%d\n", max.score-min.score);
    }

    return 0;
}
