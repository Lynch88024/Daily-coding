// 堆 -> 大顶堆 的操作
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
int heap[maxn], n = 10; // heap为堆, n为元素个数

// 堆heap数组在[low,high]范围内进行向下调整
void downAdjust(int low, int high) // low为欲调整结点的数组下标, high为堆的最后一个元素的数组下标
{
    int i = low, j = 2*i; // i为欲调整结点， j为其左结点
    while(j <= high) // 存在孩子结点
    {
        if(j+1 <= high && heap[j+1] > heap[j]) 
        {
            j = j + 1; // 令j为左右孩子结点中较大的下标
        }
        if(heap[j] > heap[i])
        {
            swap(heap[j], heap[i]); 
            i = j;
            j = 2*i;
        }
        else
        {
            break;
        }
    }
}

// 堆heap数组在[low,high]范围内进行向上调整
void upAdjust(int low, int high)
{
    int i = high, j = i/2;
    while(j >= low)
    {
        if(heap[j] < heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i/2;
        }
        else
        {
            break;
        }
    }
}

// 建堆
void createHeap()
{
    for(int i=n/2; i>=1; i--)
    {
        downAdjust(i, n);
    }
}

// 删除堆顶元素
void deleteTop()
{
    heap[1] = heap[n--];
    downAdjust(1, n);
}

// 添加元素
void insert(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}

/**************************堆排序**************************/
void heapSort()
{
    createHeap();
    for(int i=n; i>1; i--)
    {
        swap(heap[i], heap[1]); // heap[1]最大，交换到最后
        downAdjust(1, i-1);
    }
}

