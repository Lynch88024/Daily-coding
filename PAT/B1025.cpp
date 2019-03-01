#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node
{
    int address;
    int data;
    int next;
    int number;
}node[maxn];

bool cmp(Node a, Node b)
{
    return a.number < b.number; 
}

void swap(Node *a, Node *b)
{
    Node *temp;
    temp = a;
    a = b;
    b = temp; 
}  

int main()
{
    int start, n, k; 
    scanf("%d %d %d", &start, &n, &k);
    int address, data, next;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    for(int i=0; i<maxn; i++)
    {
        node[i].number = maxn; 
    }
    int p = start, count = 0;
    while(p != -1)
    {
        node[p].number = count++;
        p = node[p].next;
    }
    
    sort(node, node+maxn, cmp); 
    for(int i=0; i<count/k; i++) // cyc组需要逆序
    {
        for(int j=0; j<k/2; j++) // 每组内交换k/2次
        {
            swap(node[j+i*k], node[(i+1)*k-(j+1)]);
        }
    }
    for(int i=0; i<count-1; i++)
    {
        node[i].next = node[i+1].address;
    }
    node[count-1].next = -1;
    for(int i=0; i<count; i++)
    {
        if(node[i].next == -1)
            printf("%05d %d %d\n", node[i].address, node[i].data, node[i].next);
        else 
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
    }

    return 0;
}