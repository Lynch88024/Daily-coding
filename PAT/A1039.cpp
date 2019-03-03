#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 26*26*26*10+10;
vector<int> hashtable[maxn];

int getID(char name[])
{
    int id = 0;
    for(int i=0; i<3; i++)
    {
        id = id * 26 + (name[i] - 'A'); 
    }
    id = id * 10 + (name[3] - '0');

    return id;
}

int main()
{
    int stu, cou;
    scanf("%d %d", &stu, &cou);
    int order_cou, num_stu;
    char name[6];
    for(int i=0; i<cou; i++)
    {
        scanf("%d %d", &order_cou, &num_stu);
        for(int j=0; j<num_stu; j++)
        {
            scanf("%s", name);
            int id = getID(name);
            hashtable[id].push_back(order_cou);
        }
    }
    for(int i=0; i<stu; i++)
    {
        scanf("%s", name);
        int id = getID(name);
        printf("%s %d", name, hashtable[id].size());
        sort(hashtable[id].begin(), hashtable[id].end()); 
        for(int j=0; j<hashtable[id].size(); j++)
        {
            printf(" %d", hashtable[id][j]);
        }
        printf("\n");
    }

    return 0;
}