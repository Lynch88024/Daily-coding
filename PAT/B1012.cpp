#include <iostream> 
#include <stdio.h> 
using namespace std;

const int M = 1010;
int a[M] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    int num[5] = {0};
    int ans[5] = {0};
    int flag = 1;

    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
        if((a[i]%5 == 0))
        {
            if(a[i]%2 == 0)
            {
                num[0]++;
                ans[0] += a[i];  
            }
        }
        else if(a[i]%5 == 1)
        {
            num[1]++;
            ans[1] += flag * a[i];
            flag *= -1 ;
        }

        else if(a[i]%5 == 2)
        {
            num[2]++;
            ans[2] = num[2];
        }
        else if(a[i]%5 == 3)
        {
            num[3]++;
            ans[3] += a[i];
        }
        else if(a[i]%5 == 4)
        {
            num[4]++;
            if(a[i]>ans[4])
            {
                ans[4] = a[i];
            }
        }
    }

    if(num[0]==0)
        printf("N ");
    else
        printf("%d ", ans[0]);
    if(num[1]==0)
        printf("N ");
    else 
        printf("%d ", ans[1]);
    if(num[2]==0)
        printf("N ");
    else
        printf("%d ", ans[2]);
    if(num[3]==0)
        printf("N ");
    else
        printf("%.1f ", (double)ans[3]/num[3]);
    if(num[4]==0)
        printf("N");
    else
        printf("%d", ans[4]);

    return 0;
}




