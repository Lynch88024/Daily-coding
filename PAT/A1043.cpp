#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1010;
int input[maxn], pre[maxn], pre_m[maxn], post[maxn], post_m[maxn]; 
                                                                    
struct node
{
    int data;
    node* lchild; 
    node* rchild;
};

void insert(node* &root, int x) // 搜索二叉树插入操作
{
    if(root == NULL)
    {
        root = new node;
        root -> data = x;
        root -> lchild = NULL;
        root -> rchild = NULL;
        return ;
    }
    if(x < root->data)
    {
        insert(root->lchild, x);
    }
    else
    {
        insert(root->rchild, x); 
    }
}

node* Create(int data[], int n) // 搜索二叉树建立操作
{
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

void insert_mirror(node* &root, int x) // 镜像搜索二叉树插入操作
{
    if(root == NULL)
    {
        root = new node;
        root -> data = x;
        root -> lchild = NULL;
        root -> rchild = NULL;
        return ;
    }
    if(x < root->data)
    {
        insert_mirror(root->rchild, x);
    }
    else
    {
        insert_mirror(root->lchild, x); 
    }
}

node* Create_mirror(int data[], int n) // 镜像搜索二叉树建立操作
{
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        insert_mirror(root, data[i]);
    }
    return root;
}

int cnt_pre = 0;
void preorder(node* root, int data_pre[]) // 先序遍历
{
    if(root == NULL)
    {
        return ;
    }
    data_pre[cnt_pre++] = root -> data;
    preorder(root->lchild, data_pre);
    preorder(root->rchild, data_pre);
}

int cnt_post = 0;
void postorder(node* root, int data_post[]) // 后序遍历
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->lchild, data_post);
    postorder(root->rchild, data_post);
    data_post[cnt_post++] = root -> data;
}

bool equal(int a[], int b[], int n) // 判断数组是否相等
{
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void print(int n, int a[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d", a[i]);
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
        scanf("%d", &input[i]);
    }
    node* root = Create(input, n); 
    node* root_mirror = Create_mirror(input, n);
    preorder(root, pre);
    cnt_pre = 0; // !!!!!!!!!!!! 一定要记得清零
    preorder(root_mirror, pre_m);
    postorder(root, post);
    cnt_post = 0;
    postorder(root_mirror, post_m);
   
    if(equal(input, pre, n)==true)
    {
        printf("YES\n");
        print(n, post);
    }
    else if(equal(input, pre_m, n)==true)
    {
        printf("YES\n");
        print(n, post_m);
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}