// 二叉查找树

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node 
{
    int data;
    node* lchild;
    node* rchild;
};

node* newnode(int v) // 新建结点
{
    node* root = new node;
    root -> data = v;
    root -> lchild = NULL;
    root -> rchild = NULL;

    return root;
}

void search(node* root, int x) // 查找
{
    if(root == NULL)
    {
        printf("ERROR\n");
        return ;
    }
    if(root->data == x)
    {
        printf("%d\n", root->data);
    }
    else if(x < root->data)
    { 
        search(root->lchild, x);
    }
    else
    {
        search(root->rchild, x);
    }
}

void insert(node* &root, int x) // 插入
{
    if(root == NULL)
    {
        newnode(x);
        return ;
    }
    if(x == root->data)
    {
        return ;
    }
    else if(x < root->data)
    {
        insert(root->lchild, x);
    }
    else
    {
        insert(root->rchild, x);
    }
}

node* Create(int data[], int n) // 树的建立
{
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        insert(root, data[i]);
    }

    return root;
}

/**************************二叉树的删除*****************************/

node* findMax(node* root)  // 前驱——寻找以root为根节点,比其小的最大权值结点
{
    while(root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root)  // 后继——寻找以root为根节点,比其大的最小权值结点
{
    while(root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

void deletenode(node* &root, int x) // 结点的删除
{
    if(root == NULL)
    {
        return ;
    }
    if(root->data == x)
    {
        if(root->lchild==NULL && root->rchild==NULL) // 无左、右孩子结点
        {
            root = NULL;
        }
        else if(root->lchild != NULL) // 存在左孩子结点 -> 找前驱
        {
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deletenode(pre, pre->data);
        }
        else // 存在右孩子结点 -> 找后继
        {
            node* next = findMin(root->rchild);
            root->data = next->data;
            deletenode(next, next->data);   
        }
    }
    else if(x < root->data)
    {
        deletenode(root->lchild, x); 
    }
    else
    {
        deletenode(root->rchild, x); 
    }
    
}

/****************************二叉树镜像*****************************/
void mirror(node* root) // 法一
{
    if(root == NULL)
    {
        return ;
    }
    if(root->lchild==NULL && root->rchild==NULL)
    {
        return ;
    }
    node* temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    mirror(root->lchild);
    mirror(root->rchild);
}

void post_(node* root) // 法二
{
    if(root == NULL)
        return ;
    post_(root->lchild);
    post_(root->rchild);
    swap(root->lchild, root->rchild);
}


