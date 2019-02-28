// 创建链表

#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* create(int n, int array[])
{
    node *head, *p, *pre;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i=0; i<n; i++)
    {
        p = new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }

    return head;
}

// int main()
// {
//     int array[5] = {5,3,6,1,2};
//     node *L = create(5, array);
//     L = L->next;
//     while(L != NULL)
//     {
//         printf("%d ", L->data);
//         L = L->next;
//     }

//     return 0;
// }