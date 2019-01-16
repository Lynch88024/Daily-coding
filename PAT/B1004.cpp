#include <iostream> 
#include <cstdio> 
using namespace std;

const int M = 1010;

int main()
{
    struct student 
    {
        char name[15];
        char number[15];
        int score;
    } max, min;
    int n = 0;
    scanf("%d", &n);
    student stu[M];
    max.score = -1;
    min.score = 101;
    for(int i=0; i<n; i++)
    {
        scanf("%s %s %d", stu[i].name, stu[i].number, &stu[i].score);
        if(stu[i].score > max.score)
        {
            max = stu[i];
        }
        if(stu[i].score < min.score)
        {
            min = stu[i];
        }
    }
    printf("%s %s\n", max.name, max.number);
    printf("%s %s\n", min.name, min.number);

    return 0;
}