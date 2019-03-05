// 一般树的遍历

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 30;

struct Node
{
    int data;
    vector<int> child;
}node[maxn];

void preorder(int root) // 先序遍历
{
    printf("%d ", node[root].data);
    for(int i=0; i<node[root].child.size(); i++)
    {
        preorder(node[root].child[i]);
    }
}

void layerorder(int root) // 层次遍历
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        printf("%d ", node[now].data);
        q.pop();
        for(int i=0; i<node[now].child.size(); i++)
        {
            q.push(node[now].child[i]);
        }
    }
}

struct Node_n
{
    int data;
    int layer; // 所属层
    vector<int> child;
}node_n[maxn];

void layerorder_cnt(int root) // 记录层数的层次遍历
{
    queue<int> qq;
    node_n[root].layer = 0;
    while(!qq.empty())
    {
        int now = qq.front();
        printf("%d ", node_n[now].data);
        qq.pop();
        for(int i=0; i<node_n[now].child.size(); i++)
        {
            int child = node_n[now].child[i];
            node_n[child].layer = node_n[now].layer + 1;
            qq.push(child);
        }
    }  
}