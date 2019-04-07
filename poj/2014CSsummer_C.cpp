#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    while(scanf("%d %d", &a, &b)!=EOF && (a!=0 && b!=0))
    {
        int cnt = 0;
        a = max(a, b);
        b = min(a, b);
        while(a/b < 2)
        {
            cnt++;
            a = b;
            b = a/b;
        }
        if(cnt%2 == 0)
        {
            printf("win\n");
        }
        else 
        {
            printf("lose\n");
        }
    }
    fclose(stdin);

    return 0;
}