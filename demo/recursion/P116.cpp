/*
*   n皇后问题　ｎ个皇后两两不在一行，不在一列，不在同一对角线上
*   两种方法:　１、暴力法 ２、回溯法
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

void F(int index)
{
    if(index == n+1)
    {
        bool flag = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(abs(i-j) == abs(P[i]-P[j]))
                {
                    flag = false;
                }
            }
        }
        if(flag)
        {
            count++;
        }

        return ;
    }
    for(int x=1; x<=n; x++)
    {
        if(hashtable[x] == false)
        {
            P[index] = x;
            hashtable[x] = true;
            F(index+1); 
            hashtable[x] = false;
        }
    }
}

void FF(int index)
{
    if(index == n+1)
    {
        count++;
        return ;
    }
    for(int x=1; x<=n; x++)
    {
        if(hashtable[x] == false)
        {
            bool flag = true;
            for(int pre=1; pre<index; pre++) // 遍历之前的皇后，不能取到index
            {
                if(abs(index-pre) == abs(x-P[pre])) // 判断x是否可以赋值给P[index]
                {
                    flag = false;
                    break;
                }
            }
            if(flag) // 满足要求的x才赋值给P[index]
            {
                P[index] = x;
                hashtable[x] = true;
                FF(index+1);
                hashtable[x] = false;
            }
        }
    }
}

int main()
{
    n = 8;   
    FF(1);
    cout << count << endl;

    return 0;
}