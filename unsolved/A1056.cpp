#include <cstdio>
#include <iostream> 
#include <queue> 
using namespace std;

const int maxn = 1010;
struct mouse 
{
    int weight;
    int range;
}mouse[maxn];
queue<int> q;

int main()
{
    int np, ng;
    scanf("%d %d", &np, &ng);
    for(int i=0; i<np; i++)
    {
        scanf("%d", &mouse[i].weight);
    }
    int order; 
    for(int i=0; i<np; i++)
    {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np;
    int group;
    while(q.size() != 1)
    {
        if(temp % ng == 0)
            group = temp / ng;
        else
            group = temp / ng + 1;
        for(int i=0; i<group; i++)
        {
            int k = q.front();
            for(int j=0; j<ng; j++)
            {
                if(i*ng+j > temp)
                    break;
            }
        }
    }

    return 0;
}