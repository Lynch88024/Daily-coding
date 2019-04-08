#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
     freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int a, b;
        int left = 0, right = 0;
        scanf("%d %d", &a, &b);
        while(!(a==1 && b==1))
        {
            if(a >= b) // 左孩子结点
            {
                if(a%b != 0)
                {
                    left += a/b;
                    a %= b;
                }
                else 
                {
                    left += a/b - 1;
                    a = 1;
                }
            }
            else // 右孩子结点
            {
                if(b%a != 0)
                {
                    right += b/a;
                    b %= a;
                }
                else 
                {
                    right += b/a - 1;
                    b = 1;
                }
            }
        }
        printf("Scenario #%d:\n", i);
        printf("%d %d\n\n", left, right);
    }
    // fclose(stdin);

    return 0;
}