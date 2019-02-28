// 删除结点
#include <iostream>
#include <cstdio>
using namespace std;
#include "P256.cpp"

void del(node *L, int x)
{
    node *pre = L;
    node *p = L->next;
    while(p != NULL)
    {
        if(p->data == x)
        {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    int array[5] = {5,5,6,1,2};
    node *L = create(5, array);
    del(L, 5);
    L = L->next;
    while(L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }   

    return 0;
}