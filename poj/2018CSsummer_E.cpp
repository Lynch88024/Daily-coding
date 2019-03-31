/*
逆序对的数量，实质上就是在归并过程当中(右半部分逐个插入到左半部分)，左半部分向右移动元素的次数
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200010;
int array[maxn], temp[maxn];
long long ans = 0; // 重要逆序对个数，有可能超过int范围，要用long long 

void merge(int left, int mid, int right) // 归并
{
    int i = left;
    int j = mid + 1;
    int pos = left; // 递增的计数器
    // 计算“重要逆序对”时不能像“逆序对”那样，将计数嵌入到归并过程当中去，会改变时间复杂度超过O(nlogn)
    while(i<=mid && j<=right) 
    {
        if(array[i] <= 2*array[j]) // 不满足重要逆序对条件
        {
            i++;
        }
        else 
        {
            j++;
            ans += mid-i+1; // 计数
        }
    }
    i = left, j = mid+1, pos = left; // 恢复初始
    while(i<=mid && j<=right) // 从小到大排序存储
    {
        if(array[i] <= array[j])
        {
            temp[pos++] = array[i++];
        }
        else 
        {
            temp[pos++] = array[j++];
            // ans += mid-i+1; // 在“逆序对”中，直接在这里计数就好
        }
    }
    while(i <= mid)
    {
        temp[pos++] = array[i++];
    }
    while(j <= right)
    {
        temp[pos++] = array[j++];
    }
    for(int i=left; i<=right; i++)
    {
        array[i] = temp[i];
    }
}

void mergesort(int left, int right) // 归并排序
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, mid, right);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }
    mergesort(0, n-1);
    printf("%lld", ans);
    // fclose(stdin);

    return 0;
}