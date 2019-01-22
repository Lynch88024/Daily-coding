#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N], b[N]; 

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }    
    scanf("%d", &m);
    int median = (n + m -1) / 2;
    int cnt = 0;
    int aa = 0;
    for(int i=0; i<m; i++)
    {
        scanf("%d", &b[i]);
        if(cnt < median)
        {
            if(b[i] > a[aa])
            {
                aa++;
            }
            cnt++;
        }
        else
        {
            if(b[i] > a[aa])
            {
                printf("%d", a[aa]);
            }
            else
            {
                printf("%d", b[i]);
            }
        }
    }
    // sort(a, a+n);
    // sort(b, b+m);

    // int median = (n + m -1) / 2;
    // int i = 0;
    // int j = 0;
    // int cnt = 0;
    // while(cnt++ < median)
    // {
    //     if(a[i] <= b[j])
    //     {
    //         i++;
    //     }
    //     else
    //     {
    //         j++;
    //     }
    // }
    // if(a[i] < b[j])
    // {
    //     printf("%d", a[i]);
    // }
    // else
    // {
    //     printf("%d", b[j]);
    // }

    // merge(n, m);
    // printf("%d", c[(m+n-1)/2]);

    return 0;
}

// void merge(int n, int m)
// {
//     int i = 0;
//     int j = 0;
//     int cnt = 0;
//     while(i<n && j<m)
//     {
//         if(a[i] <= b[j])
//         {
//             c[cnt++] = a[i++];
//         }
//         else
//         {
//             c[cnt++] = b[j++];
//         }
//     }
//     while(i < n)
//     {
//         c[cnt++] = a[i++];
//     }
//     while(j < m)
//     {
//         c[cnt++] = b[j++];
//     }
// }