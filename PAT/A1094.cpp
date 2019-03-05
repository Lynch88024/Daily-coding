#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 105;
int hashtable[maxn] = {0};

struct Node
{
    int layer;
    vector<int> child;
}node[maxn];

void levelorder(int root)
{
    queue<int> q;
    node[root].layer = 1;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0; i<node[now].child.size(); i++)
        {
            int child = node[now].child[i];
            node[child].layer = node[now].layer + 1;
            q.push(child);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n ,&m);
    int num, temp, index;  
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &index, &num);
        for(int j=0; j<num; j++)
        {
            scanf("%d", &temp);
            node[index].child.push_back(temp);
        }
    }
    levelorder(1);
    for(int i=1; i<=n; i++)
    {
        hashtable[node[i].layer]++;
    }
    int cnt_max = 0, ans = 1;
    for(int i=1; i<=n; i++)
    {
        if(hashtable[i] > cnt_max)
        {
            cnt_max = hashtable[i];
            ans = i;
        }
    }
    printf("%d %d", cnt_max, ans);

    return 0;
}
