// 查找元素，并统计元素个数

#include <iostream>
#include <cstdio>
using namespace std;
#include "P256.cpp"
int search(node *L, int x)
{
    int count = 0;
    node *p = L->next;
    while(p != NULL)
    {
        if(p->data == x)
        {
            count++;
        }
        p = p->next;
    }

    return count;
}

int main()
{
    int array[5] = {5,5,6,1,2};
    node *L = create(5, array);
    int count = search(L, 5);
    printf("%d", count);

    return 0;
}