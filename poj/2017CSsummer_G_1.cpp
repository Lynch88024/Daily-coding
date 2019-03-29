#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int heap[maxn] = {0};

// 对heap在[low, high]范围内进行调整
void downAdjust(int low, int high) // 向下调整
{
    int i = low; // i为待调整接点
    int j = 2 * i; // j为其左孩子
    while(j <= high) // 左孩子存在
    {
        if(j+1<=high && heap[j+1]<heap[i]) // 右孩子存在，且小于父亲结点
        {
            j = j + 1; // 使j保持为最大的那个孩子结点
        }
        if(heap[j] < heap[i]) // 小顶堆 孩子结点<父亲结点 时进行调整
        {
            swap(heap[j], heap[i]);
            i = j; 
            j = 2 * i;
        }
        else 
        {
            break;
        }
    }
}

void upAdjust(int low, int high) // 向上调整
{
    int i = high; // i为待调整结点
    int j = i / 2; // j为其父亲结点
    while(j >= low) // 父亲结点存在
    {
        if(heap[j] > heap[i]) // 小顶堆 父亲结点>孩子结点 时进行调整
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }
        else
        {
            break;
        }
    }
}

/*
// 建堆
void createHeap(int n)
{
    for(int i=n/2; i>=1; i--)
    {
        downAdjust(i, n);
    }
}

// 堆排序
void heapSort(int n)
{
    createHeap(n);
    for(int i=n; i>1; i++)
    {
        swap(heap[i], heap[1]);
        downAdjust(1, i-1);
    }
}
*/

// 删除堆顶结点
void deleteHeap(int &n) // 一定要加引用才能改变实参
{
    printf("%d\n", heap[1]);
    heap[1] = heap[n--]; // 最后一个结点覆盖堆顶结点,长度-1
    downAdjust(1, n); // 向下调整堆顶元素
}

// 插入新结点
void insertHeap(int &n, int x)
{
    heap[++n] = x; // 数组末尾赋值x，长度+1
    upAdjust(1, n); // 向上调整新加入的结点
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n, type;
        scanf("%d", &n);
        int cnt = 0; // 记录堆结点个数
        for(int j=0; j<n; j++)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                int u;
                scanf("%d", &u);
                insertHeap(cnt, u); // 插入结点
            }
            if(type == 2)
            {
                deleteHeap(cnt); // 删除堆顶结点
            }
        }
    }
    // fclose(stdin);

    return 0;
}