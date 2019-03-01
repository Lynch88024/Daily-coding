#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int maxm = 10010;

struct Node
{
    int address;
    int data;
    int next;
    int order_1;
    int order_2;
}node[maxn];

bool hashtable[maxm] = {false};

bool cmp(Node a, Node b)
{
    if(a.order_1 != b.order_1)
        return a.order_1 < b.order_1;
    else 
        return a.order_2 < b.order_2;
}

int main()
{
    int start, n;
    scanf("%d %d", &start, &n);
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
        node[i].order_1 = maxn; 
        node[i].order_2 = maxn; 
    }
    int p = start, count_1 = 0, count_2 = 0;
    while(p != -1)
    {
        if(hashtable[abs(node[p].data)] == false)
        {
            node[p].order_1 = count_1++;
            hashtable[abs(node[p].data)] = true;
            p = node[p].next;
        }
        else
        {
            node[p].order_2 = count_2++;
            p = node[p].next;
        }
    }
    sort(node, node+maxn, cmp);
    for(int i=0; i<count_1-1; i++)
    {
        node[i].next = node[i+1].address;
    }
    node[count_1-1].next = -1;
    for(int i=count_1; i<count_1+count_2-1; i++)
    {
        node[i].next = node[i+1].address;
    }
    node[count_1+count_2-1].next = -1;
    for(int i=0; i<count_1+count_2; i++)
    {
        if(node[i].next == -1)
            printf("%05d %d %d\n", node[i].address, node[i].data, node[i].next);
        else 
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
    }

    return 0;
}