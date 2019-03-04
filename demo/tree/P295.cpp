// 由中序遍历+另一种遍历 得到其所能确定的树

#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};
char *pre; // 先序序列
char *in; // 中序序列
char *post; // 后序序列 

node* Create_a(int pre_L, int pre_R, int in_L, int in_R) // 前序+中序
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
        if(in[k] == pre[pre_L])
        {
            break;
        }
    } 
    int num_Left = k - in_L; // 左子树的结点数
    root -> lchild = Create_a(pre_L+1, pre_L+num_Left, in_L, k-1);
    root -> rchild = Create_a(pre_L+num_Left+1, pre_R, k+1, in_R);

    return root;
}

node* Create_b(int post_L, int post_R, int in_L, int in_R) // 后序+中序
{
    if(post_L > post_R)
    {
        return NULL;
    }
    node* root = new node;
    root -> data = post[post_R];
    int k;
    for(k=in_L; k<=in_R; k++)
    {
        if(in[k] == post[post_R])
        {
            break;
        }
    } 
    int num_Left = k - in_L; // 左子树的结点数
    root -> lchild = Create_b(post_L, post_L+num_Left-1, in_L, k-1);
    root -> rchild = Create_b(post_L+num_Left, post_R-1, k+1, in_R);

    return root;
}