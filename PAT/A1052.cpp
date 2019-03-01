#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

const int maxn = 100010;

struct Node 
{
    int address;
    int key;
    int next;
    int flag;
}node[maxn];

bool cmp(Node a, Node b) 
{
    if(a.flag==0 || b.flag==0)
    {
        return a.flag > b.flag;
    }
    else
    {
        return a.key < b.key;
    }
}

int main()
{
    int n, begin;
    scanf("%d %d", &n, &begin);
    int address, key, next;
    for(int i=0; i<maxn; i++) 
    {
        node[i].flag = 0;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &address, &key, &next);
        node[address].address = address;
        node[address].key = key;
        node[address].next = next;
    }

    int p = begin, count = 0;
    while(p != -1)
    {
        node[p].flag = 1;
        count++;
        p = node[p].next;
    }
    if(count == 0)
        printf("0 -1");
    else
    {
        sort(node, node+maxn, cmp);
        for(int i=0; i<count-1; i++)
        {
            node[i].next = node[i+1].address;
        }
        node[count-1].next = -1;
        printf("%d %05d\n", count, node[0].address);
        for(int i=0; i<count; i++)
        {
            if(node[i].next == -1)
                printf("%05d %d %d\n", node[i].address, node[i].key, node[i].next);
            else
                printf("%05d %d %05d\n", node[i].address, node[i].key, node[i].next);
        }       
    }

    return 0;
}