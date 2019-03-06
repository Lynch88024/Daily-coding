#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 105;
int input[maxn], output[maxn];

struct Node
{
    int data;
    int lchild;
    int rchild;
}node[maxn]; 

int cnt = 0;
void inorder(int root, int a[])
{
    if(root == -1)
    {
        return ;
    }
    inorder(node[root].lchild, a);
    node[root].data = a[cnt++];
    inorder(node[root].rchild, a); 
}

void levelorder(int root)
{
    int cnt = 0;
    queue<int> q;
    q.push(root); 
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        output[cnt++] = node[now].data;
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
    for(int i=0; i<n; i++)
    {
        printf("%d", output[i]);
        if(i != n-1)
        {
            printf(" ");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int lchild, rchild;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &lchild, &rchild);
        node[i].lchild = lchild;
        node[i].rchild = rchild;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &input[i]);
    }
    sort(input, input+n);  
    inorder(0, input);
    levelorder(0);
    print(n);

    return 0;
}