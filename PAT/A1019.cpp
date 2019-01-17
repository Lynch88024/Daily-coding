#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
    int n = 0;
    int b = 0;
    scanf("%d %d", &n, &b);
    int num = 0;
    int change[40] = {0};
    do
    {
        change[num++] = n % b;
        n /= b;
    }while(n != 0);
    if(num == 1)
    {
        printf("Yes\n");
    }
    else
    {
        int flag = 1;
        for(int i=0; i<num/2; i++)
        {
            if(change[i] != change[num-1-i])
            {
                flag = 0;
                printf("No\n");
                break;
            }
        }
        if(flag == 1)
        {
            printf("Yes\n");
        }
    }
    printf("%d", change[num-1]);
    for(int i=num-2; i>=0; i--)
    {
        printf(" %d", change[i]);
    }

    return 0;
}