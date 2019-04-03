#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1010;
char pre[maxn], in[maxn], post[maxn];

struct node
{
    char data;
    node* lchild;
    node* rchild;
};

node* Change(int pre_L, int pre_R, int in_L, int in_R)
{
    if(pre_L > pre_R) // 边界条件
    {
        return NULL;
    }
    node* root = new node;
    root -> data = pre[pre_L]; // 根结点
    int k; // 中序数组中根结点的下标
    for(k=in_L; k<=in_R; k++)
    {
        if(in[k] == pre[pre_L])
        {
            break;
        }
    }
    int num_left = k - in_L; // 左子树结点的个数
    root -> lchild = Change(pre_L+1, pre_L+num_left, in_L, k-1); // 左子树
    root -> rchild = Change(pre_L+num_left+1, pre_R, k+1, in_R); // 右子树

    return root;
}

void postorder(node* root) // 后序遍历
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%c", root->data);
}

int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%s %s", pre, in) != EOF)
    {
        int len_pre = strlen(pre);
        int len_in = strlen(in);
        node* tree = Change(0, len_pre-1, 0, len_in-1);
        postorder(tree);
        printf("\n");
    }
    fclose(stdin);

    return 0;
}