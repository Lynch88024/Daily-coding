/*
*   从N个中选K个
*   方法:   DFS搜索 
*   @author Lynch <2628477079@qq.com>
*/

#include <cstdio> 
#include <iostream>
#include <vector> 
using namespace std;

const int maxn = 20;

int A[maxn] = {2,3,3,4};
int n, k, target, maxsum_squ = 0;
vector<int> temp, ans;

void DFS(int index, int num, int sum, int sum_squ)
{
    if(num==k && sum==target) // 返回条件1
    {
        if(sum_squ > maxsum_squ) // 参数更新
        {
            maxsum_squ = sum_squ; 
            ans = temp;
        }
        return ;
    }
    if(index == n || num > k || sum > target) // 返回条件2
    {
        return ;
    } 
    DFS(index+1, num, sum, sum_squ);
    temp.push_back(A[index]);
    DFS(index+1, num+1, sum+A[index], sum_squ+A[index]*A[index]); 
    temp.pop_back();
}

int main()
{
    n = 4;
    k = 2;
    target = 6;
    DFS(0,0,0,0);
    for(vector<int>::iterator it=ans.begin(); it!=ans.end(); it++)
    {
        printf("%d ", *it);
    }

    return 0;
}