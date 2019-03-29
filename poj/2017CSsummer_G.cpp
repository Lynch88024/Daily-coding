#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q; // 小堆顶结构

int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n, type;
        scanf("%d", &n);
        for(int j=0; j<n; j++)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                int u;
                scanf("%d", &u);
                q.push(u);
            }
            if(type == 2)
            {
                printf("%d\n", q.top());
                q.pop();
            }
        }
    }
    // fclose(stdin);

    return 0;
}