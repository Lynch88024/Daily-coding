/*
*   n皇后问题　ｎ个皇后两两不在一行，不在一列，不在同一对角线上
*   基于回溯法的另一种写法
*   @author Lynch <2628477079@qq.com>
*/

#include <cstdio> 
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 15;
int n, count = 0;
int P[maxn];
bool hashtable[maxn] = {false};

void FF(int index)
{
    if(index >= 2) // 将约束条件写在前边，不满足条件时直接return
    {
        for(int pre=1; pre<index; pre++) // 遍历之前的皇后，不能取到index
        {
            if(abs(index-pre) == abs(P[index]-P[pre])) // 判断x是否可以赋值给P[index]
            {
                return ;
            }
        }
    }
    if(index == n)
    {
        count++;
        return ;
    }
    for(int x=1; x<=n; x++)
    {
        if(hashtable[x] == false)
        {
            P[index+1] = x;
            hashtable[x] = true;
            FF(index+1); 
            hashtable[x] = false;
        }
    }
}

int main()
{
    n = 5;   
    FF(0);
    cout << count << endl;

    return 0;
}