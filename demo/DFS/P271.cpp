/*
*   装包问题 —— 有限容量下，装包价值最大
*   两种方法:   DFS搜索 or 改进的DFS搜索
*   @author Lynch <2628477079@qq.com>
*/

#include <cstdio> 
#include <iostream> 
using namespace std;

const int maxn = 25;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sum_w, int sum_c)
{
    if(index == n) // 返回条件
    {
        if(sum_w<=V && sum_c>maxValue) // 参数更新
        {
            maxValue = sum_c;
        }
        return ;
    }
    DFS(index+1, sum_w, sum_c);
    DFS(index+1, sum_w+w[index], sum_c+c[index]); 
}

void DFS_new(int index, int sum_w, int sum_c)
{
    if(index == n)
    {
        return ;
    }
    DFS(index+1, sum_w, sum_c);
    if(sum_w+w[index] <= V)  // 只有小于V，才能进入"装入包"分支
    {
        if(sum_c+c[index] > maxValue)
        {
            maxValue = sum_c + c[index];
        }
        DFS(index+1, sum_w+w[index], sum_c+c[index]); 
    }
}

int main()
{
    scanf("%d %d", &n, &V);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &w[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &c[i]);
    }
    DFS_new(0,0,0); 
    printf("%d\n", maxValue);

    return 0;
}