#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

node* newNode(int v) // 创建新结点
{
    node* Node = new node;
    Node -> data = v;
    Node -> lchild = NULL;
    Node -> rchild = NULL;

    return Node;
}

void insert(node* &root, int x) // 插入新结点
{
    if(root == NULL)
    {
        root = newNode(x);
        return ;
    }
    insert(root->lchild, x);
    insert(root->rchild, x);
}

node* Create(int data[], int n) // 二叉树的创建
{
    node *root = NULL;
    for(int i=0; i<n; i++)
    {
        insert(root, data[i]);
    }

    return root;
}

void Search(node* root, int x, int newdata) // 二叉树结点的查找、修改
{
    if(root == NULL)
    {
        return ;
    }
    if(root->data == x)
    {
        root -> data = newdata;
    }
    Search(root->lchild, x, newdata);
    Search(root->rchild, x, newdata);
}

int main()
{


    return 0;
}