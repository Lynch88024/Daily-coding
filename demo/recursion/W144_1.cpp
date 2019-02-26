/*
*   汉诺塔问题——改进三： 只能相邻的两柱子间移动圆盘
*   方法:   递归 
*   @author Lynch <2628477079@qq.com>
*/

#include <iostream> 
#include <cstdio> 
using namespace std;

int tower(int n)
{
    if(n == 1)
    {
        return 2;
    }
    else
    {
        return 3 * tower(n-1) + 2;
    }
    
}

int main()
{
    int n = 12;
    int ans = tower(n);
    cout << ans << endl;

    return 0;
}