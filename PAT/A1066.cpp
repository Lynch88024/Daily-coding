#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 25;
int input[maxn];

struct node
{
    int data;
    int height;
    node* lchild;
    node* rchild;
};

node* newNode(int v)
{
    node* Node = new node;
    Node -> data = v;
    Node -> height = 1;
    Node -> lchild = NULL;
    Node -> rchild = NULL;

    return Node;
}

int getHeight(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root -> height;
}

void updateHeight(node* root)
{
    root -> height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1; 
}

int getBF(node* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root)
{
    node* temp = root -> rchild;
    root -> rchild = temp -> lchild;
    temp -> lchild = root;
    updateHeight(root);
    updateHeight(temp); 
    root = temp;
}

void R(node* &root)
{
    node* temp = root -> lchild;
    root -> lchild = temp -> rchild;
    temp -> rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp; 
}

void insert(node* &root, int v)
{
    if(root == NULL)
    {
        root = newNode(v); 
        return ;
    }
    if(v < root->data)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBF(root) == 2)
        {
            if(getBF(root->lchild) == 1)
            {
                R(root);
            }
            else if(getBF(root->lchild) == -1)
            {
                L(root->lchild);
                R(root); 
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if(getBF(root) == -2)
        {
            if(getBF(root->rchild) == -1)
            {
                L(root);
            }
            else if(getBF(root->rchild) == 1)
            {
                R(root->rchild);
                L(root); 
            }
        }
    }
}

node* Create(int data[], int n)
{
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        insert(root, data[i]); 
    }

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &input[i]);
    }
    node* root = Create(input, n);
    printf("%d", root->data);

    return 0;
}