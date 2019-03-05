#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 35;
int post[maxn], in[maxn], level[maxn];

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* Create(int post_L, int post_R, int in_L, int in_R)
{
    if(post_L > post_R)
    {
        return NULL;
    }
    node *root = new node;
    root -> data = post[post_R]; 
    int k;
    for(k=in_L; k<=in_R; k++)
    {
        if(post[post_R] == in[k])
        {
            break;
        }
    }
    int num_Left = k - in_L;
    root -> lchild = Create(post_L, post_L+num_Left-1, in_L, k-1);
    root -> rchild = Create(post_L+num_Left, post_R-1, k+1, in_R); 

    return root;
}

void levelorder(node* root)
{
    queue<node*> q;
    q.push(root); 
    int cnt = 0;
    while(!q.empty())
    {
        node* now = q.front();
        q.pop();
        level[cnt++] = now -> data;
        if(now->lchild != NULL)
        {
            q.push(now->lchild); 
        }
        if(now->rchild != NULL)
        {
            q.push(now->rchild); 
        }
    }
}

void print(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d", level[i]);
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
    for(int i=0; i<n; i++)
    {
        scanf("%d", &post[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &in[i]);
    }
    node* root = Create(0, n-1, 0, n-1);
    levelorder(root);
    print(n);

    return 0;
}