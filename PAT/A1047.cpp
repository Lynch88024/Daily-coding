#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 2510;
const int maxm = 40010;
vector<int> course[maxn];  
char name[maxm][5];

bool cmp(int a, int b)
{
    return strcmp(name[a], name[b]) < 0; 
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int num_course, order_course;
    for(int i=0; i<n; i++)
    {
        scanf("%s %d", name[i], &num_course);
        for(int j=0; j<num_course; j++)
        {
            scanf("%d", &order_course);
            course[order_course].push_back(i);
        }
    }
    for(int i=1; i<=k; i++)
    {
        sort(course[i].begin(), course[i].end(), cmp);
        int number = course[i].size();
        printf("%d %d\n", i, number);
        for(int j=0; j<number; j++)
        {
            printf("%s\n", name[course[i][j]]);    
        }    
        // if(number != 0)
        // {
        //     printf("%d %d\n", i, number);
        //     for(int j=0; j<number; j++)
        //     {
        //         printf("%s\n", name[course[i][j]]);
        //     }
        // }
    }

    return 0;
}