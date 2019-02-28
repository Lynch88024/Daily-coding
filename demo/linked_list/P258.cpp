// 插入元素

#include <iostream>
#include <cstdio>
using namespace std;
#include "P256.cpp"

void insert(node *L, int pos, int x)
{
    node *pre = L;
    for(int i=0; i<pos-1; i++)
    {
        pre = pre->next;
    }
    node *p = new node;
    p->data = x;
    p->next = pre->next;
    pre->next = p;
}

int main()
{
    int array[5] = {5,5,6,1,2};
    node *L = create(5, array);
    insert(L, 3, 5);
    L = L->next;
    while(L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }    

    return 0;
}