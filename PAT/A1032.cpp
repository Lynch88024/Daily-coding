#include <iostream>
#include <cstdio> 
#include <vector>
using namespace std;

const int maxn = 100010;

struct Node 
{
    char c;
    int next;
}node[maxn];

int main()
{
    int adr1, adr2;
    int n = 0;
    scanf("%d %d %d", &adr1, &adr2, &n);
    int index, next;
    char data;
    for(int i=0; i<n; i++)
    {
        scanf("%d %c %d", &index, &data, &next);
        node[index].c = data;
        node[index].next = next;
    }

    int temp1 = adr1;
    int temp2 = adr2;
    vector<int> list1, list2;
    while(temp1 != -1)  // 不能写 > 0 ！！！！
    {
        list1.push_back(temp1);
        temp1 = node[temp1].next;
    }
    while(temp2 != -1)
    {
        list2.push_back(temp2);
        temp2 = node[temp2].next;
    }
    int ans = -1;
    if(list1.size() <= list2.size())
    {
        int len_s = list1.size();
        int len_l = list2.size();
        int len_dis = abs(len_l - len_s);
        for(int i=len_s-1; i>=0; i--)
        {
            if(list1[i] == list2[i+len_dis])
            {
                ans = list1[i];
            }
            else
            {
                break;
            }
            
        }
    }
    else
    {
        int len_s = list2.size();
        int len_l = list1.size();
        int len_dis = abs(len_l - len_s);
        for(int i=len_s-1; i>=0; i--)
        {
            if(list2[i] == list1[i+len_dis])
            {
                ans = list2[i];
            }
            else
            {
                break;
            }
            
        }
    }
    if(ans == -1)
        printf("%d", ans);
    else
    {
        printf("%05d", ans);
    }
    
    return 0;
}