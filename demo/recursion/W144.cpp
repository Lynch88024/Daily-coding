/*
*   汉诺塔问题
*   方法:   递归 
*   @author Lynch <2628477079@qq.com>
*/

#include <cstdio>
#include <iostream>
using namespace std;

void tower(int n, char x, char y, char z) // n个圆盘，x初始塔，y辅助塔，z目标塔
{
    if(n)
    {
        tower(n-1, x, y, z); // 将n-1个圆盘从 初始塔 移到 辅助塔
        cout << "From " << x << " to " << z << endl; // 将最后一个大圆盘从 初始塔 移到 目标塔
        tower(n-1, y, z, x); // 将n-1个圆盘从 辅助塔 移到 目标塔
    }
    //return ;
}


int main()
{
    int n = 3;
    tower(n, 'A', 'B', 'C');

    return 0;
}