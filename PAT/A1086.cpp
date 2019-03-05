#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 35;
int pre[maxn], in[maxn], post[maxn];
int n;
int cnt = 0;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* Create(int pre_L, int pre_R, int in_L, int in_R)
{
    if(pre_L > pre_R)
    {
        return NULL;
    }
    node* root = new node;
    root -> data = pre[pre_L];
    int k;
    for(k=in_L; k<=in_R; k++)
    {
        if(pre[pre_L] == in[k])
        {
            break;
        }
    }
    int num_Left = k - in_L;
    root -> lchild = Create(pre_L+1, pre_L+num_Left, in_L, k-1);
    root -> rchild = Create(pre_L+num_Left+1, pre_R, k+1, in_R); 

    return root;
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    post[cnt++] = root -> data; 
}

void print()
{
    for(int i=0; i<n; i++)
    {
        printf("%d", post[i]);
        if(i != n-1)
        {
            printf(" "); 
        }
    }
}

int main()
{
    scanf("%d", &n);
    char oper[10];
    stack<int> s;
    int num;
    int pre_order = 0, in_order = 0;
    for(int i=0; i<2*n; i++)
    {
        scanf("%s", oper);
        if(strcmp(oper, "Push")==0)
        {
            scanf("%d", &num);
            pre[pre_order++] = num;
            s.push(num);
        }
        if(strcmp(oper, "Pop")==0)
        {
            in[in_order++] = s.top();
            s.pop();
        }
    }

    node *root = Create(0, n-1, 0, n-1);
    postorder(root);
    print();

    return 0;
}