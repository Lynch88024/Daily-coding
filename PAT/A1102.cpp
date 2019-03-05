#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 15;
int pre[maxn], in[maxn], post[maxn], level[maxn];

struct Node
{
    int data;
    int lchild;
    int rchild;
}node[maxn];
bool flag[maxn] = {false};
int n;
int pre_num = 0, in_num = 0, post_num = 0, level_num = 0;

int str_num(char c)
{
    if(c == '-')
        return -1;
    else
    {
        flag[c-'0'] = true; 
        return c - '0';
    }
}

void preorder(int root) // 先序遍历
{
    if(root == -1)
        return ;
    pre[pre_num++] = root;
    preorder(node[root].lchild);
    preorder(node[root].rchild);
}

void inorder(int root) // 中序遍历
{
    if(root == -1)
        return ;
    inorder(node[root].lchild); 
    in[in_num++] = root;
    inorder(node[root].rchild);
}

void postorder(int root) // 后序遍历
{
    if(root == -1)
        return ;
    postorder(node[root].lchild);
    postorder(node[root].rchild);
    // post[post_num++] = root; 
    swap(node[root].lchild, node[root].rchild); // 交换左右孩子结点
}

void levelorder(int root) // 层次遍历
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        level[level_num++] = now;
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

void print_level()
{
    for(int i=0; i<n; i++)
    {
        printf("%d", level[i]);
        if(i != n-1)
        {
            printf(" "); 
        }
    }
    printf("\n");
}

void print_in()
{
    for(int i=0; i<n; i++)
    {
        printf("%d", in[i]);
        if(i != n-1)
        {
            printf(" "); 
        }
    }
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    char temp_l, temp_r;
    for(int i=0; i<n; i++)
    {
        scanf("%*c%c %c", &temp_l, &temp_r);  // %*c 吸收回车符
        // node[i].lchild = str_num(temp_l);
        // node[i].rchild = str_num(temp_r); 
        node[i].rchild = str_num(temp_l);
        node[i].lchild = str_num(temp_r); 
    }
    int root;
    for(int i=0; i<n; i++)
    {
        if(flag[i] == false)
        {
            root = i;
            break;
        }
    }
    //postorder(root);
    levelorder(root);
    inorder(root);
    print_level();
    print_in();

    return 0;
}