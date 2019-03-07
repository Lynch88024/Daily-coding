#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    int height;
    node* lchild;
    node* rchild;
};

node* newNode(int v)   // 新建结点
{
    node* Node = new node;
    Node -> data = v;
    Node -> height = 1;
    Node -> lchild = NULL;
    Node -> rchild = NULL;

    return Node;
}

int getHeight(node* root) // 获取结点root所在子树的当前高度
{
    if(root == NULL)
    {
        return 0;
    }

    return root -> height;
}

void updateHeight(node* root) // 更新结点root的高度
{
    root -> height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBF(node *root) // 计算结点root的平衡因子——左右子树高度之差
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}



void search(node* root, int x) // 搜索
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


/****************************AVL树插入操作*****************************/
void L(node* &root) // 左旋 —— R型树 左子树高度 < 右子树高度 —— 向左旋转
{
    node* temp = root -> rchild;
    root -> rchild = temp -> lchild; // 步骤1
    temp -> lchild = root; // 步骤2
    updateHeight(root); // 更新原根节点高度
    updateHeight(temp); // 更新新根节点高度
    root = temp; // 步骤3
}

void R(node* &root) // 右旋 —— L型树 左子树高度 > 右子树高度 —— 向右旋转
{
    node* temp = root -> lchild;
    root -> lchild = temp -> rchild; // 步骤1
    temp -> rchild = root; // 步骤2
    updateHeight(root);
    updateHeight(temp);
    root = temp; // 步骤3
}

void insert(node* &root, int v) // AVL树的插入
{
    if(root == NULL)
    {
        root = newNode(v);
        return ;
    }
    if(v < root->data)
    {
        insert(root->lchild, v);
        updateHeight(root); // 更新树高
        if(getBF(root) == 2) // 左子树高度 > 右子树高度  L型树
        {
            if(getBF(root->lchild) == 1) // LL型树
            {
                R(root);
            }
            else if(getBF(root->lchild) == -1) // LR型树
            {
                L(root->lchild);
                R(root); 
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root); // 更新树高
        if(getBF(root) == -2) // 左子树高度 < 右子树高度  R型树
        {
            if(getBF(root->rchild) == -1) // RR型树
            {
                L(root);
            }
            else if(getBF(root->rchild) == 1) // RL型树
            {
                R(root->rchild);
                L(root);
            }
        }
    }
    
}

/****************************AVL树建立操作*****************************/
node* Create(int data[], int n)
{
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        insert(root, data[i]);
    }

    return root;
}