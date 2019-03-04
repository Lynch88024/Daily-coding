// 二叉树的4种遍历方式

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

void preorder(node* root) // 先序遍历
{
    if(root == NULL)
        return ;
    printf("%d\n", root->data);
    preorder(root->lchild);
    preorder(root->rchild); 
} 

void inorder(node* root) // 中序遍历
{
    if(root == NULL)
        return ;
    inorder(root->lchild);
    printf("%d\n", root->data);
    inorder(root->rchild);
}

void postorder(node* root) // 后序遍历
{
    if(root == NULL)
        return ;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n", root->data);
}

void layerorder(node* root) // 层次遍历 -> 用队列存储
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* now = q.front();
        q.pop();
        printf("%d\n", now->data);
        if(now->lchild != NULL)
        {
            layerorder(now->lchild);
        }
        if(now->rchild != NULL)
        {
            layerorder(now->rchild);
        }
    }
}

struct Node
{
    int data;
    int layer; // 层次
    Node* lchild;
    Node* rchild;
};

void layerorder_cnt(Node* root)
{
    queue<Node*> q;
    root -> layer = 1;
    q.push(root);
    while(!q.empty())
    {
        Node* now = q.front();
        q.pop();
        printf("%d\n", now->data);
        if(now->lchild != NULL)
        {
            now->lchild->layer = now->layer + 1;
            layerorder_cnt(now->lchild);
        }
        if(now->rchild != NULL)
        {
            now->rchild->layer = now->layer + 1;
            layerorder_cnt(now->rchild);
        }
    }
}
