#include <iostream> 
#include <cstdio>
using namespace std;

const int N = 100010;
const int M = 10010;
int dis[N] = {0};
int dis_0[N] = {0};
int a[M] = {0};
int b[M] = {0};
int sum_pos[M] = {0};
int sum_neg[M] = {0};
int sum[M] = {0};

int main()
{
    int n = 0;
    int sum_total = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &dis[i]);
        sum_total += dis[i];
        dis_0[i] = sum_total;
    }
    int m = 0;
    scanf("%d", &m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] > b[i])
        {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
        // for(int j=a[i]; j<b[i]; j++)
        // {
        //     sum_pos[i] += dis[j];
        // }
        sum_pos[i] = dis_0[b[i]-1]-dis_0[a[i]-1];
        sum_neg[i] = sum_total - sum_pos[i];
        if(sum_neg[i] < sum_pos[i])
            sum[i] = sum_neg[i];
        else
            sum[i] = sum_pos[i];
        
        printf("%d\n", sum[i]);
    }

    return 0;
}