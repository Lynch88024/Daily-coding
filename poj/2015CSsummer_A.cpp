#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans_1 = 0, ans_5 = 0, ans_10 = 0;
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp == 1)
        {
            ans_1++;
        }
        if(temp == 5)
        {
            ans_5++;
        }
        if(temp == 10)
        {
            ans_10++;
        }
    }
    printf("%d\n%d\n%d", ans_1, ans_5, ans_10);

    return 0;
}