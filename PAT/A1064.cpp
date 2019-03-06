#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int input[maxn], output[maxn];

struct Node
{
    int data;
    int lchild;
    int rchild;
}node[maxn];

int cnt = 1;
void inorder(int root)
{
    if(root == -1)
    {
        return ;
    }
    inorder(node[root].lchild);
    node[root].data = input[cnt++];
    inorder(node[root].rchild); 
}

void levelorder(int root)
{
    int count = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        output[count++] = node[now].data;
        if(node[now].lchild != -1)
        {
            q.push(node[now].lchild);
        }
        if(node[now].rchild != -1)
        {
            q.push(node[now].rchild);
        }
    }
}

void print(int n)
{
    for(int i=1; i<=n; i++)
    {
        printf("%d", output[i]);
        if(i != n)
        {
            printf(" ");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &input[i]);
    }
    sort(input+1, input+n+1);
    for(int i=1; i<=n/2; i++)
    {
        node[i].lchild = 2*i;
        node[i].rchild = 2*i+1;
        if(node[i].rchild > n)
        {
            node[i].rchild = -1;
        }
    }
    for(int i=n/2+1; i<=n; i++)
    {
        node[i].lchild = -1;
        node[i].rchild = -1;
    }
    inorder(1);
    levelorder(1);
    print(n);

    return 0;
}