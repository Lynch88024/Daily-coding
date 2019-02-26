#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 20;
int ans[maxn];
bool hashtable[maxn] = {false};
int n;

bool isPrime(int a, int b) // 判断a+b是否为素数
{
    int sum = a + b;
    if(sum <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * sum);
    for(int i=2; i<=sqr; i++)
    {
        if(sum % i == 0)
        {
            return false;
        }
    }

    return true;
}

void print()
{
    for(int i=1; i<=n; i++)
    {
        printf("%d", ans[i]);
        if(i != n)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void DFS(int index)
{
    if(index > 1)
    {
        if(isPrime(ans[index], ans[index-1]) == false)
        {
            return ;
        }
    }
    if(index == n) // 因为向ans[index+1]赋值,调用DFS(n)时,ans[n]在上一轮中已经被赋值，
                   // 所以等到 index==n 时,即到达终止条件
    {
        if(isPrime(ans[n], ans[1]) == false)
        {
            return ;
        }
        print();
        return ;
    }
    for(int x=2; x<=n; x++)
    {
        if(hashtable[x] == false)
        {
            ans[index+1] = x; // 因为ans[1]已经存入1，所以需向ans[index+1]赋值
            hashtable[x] = true;
            DFS(index+1);
            hashtable[x] = false;
        }
    }
}


int main()
{
    n = 6;
    ans[1] = 1;
    hashtable[1] = true;
    DFS(1);

    return 0;
}