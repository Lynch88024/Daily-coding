#include <iostream> 
#include <cstdio> 
using namespace std;

const int M = 1010;
double a[M] = {0.0};

int main()
{
    int n1, n2 = 0;
    double k1, k2 = 0.0;
    int e1, e2 = 0;
    int cnt = 0;

    scanf("%d", &n1);
    for(int i=0; i<n1; i++)
    {
        scanf("%d %lf", &e1, &k1);
        a[e1] = k1;
        cnt++;
    }
    scanf("%d", &n2);
    for(int i=0; i<n2; i++)
    {
        scanf("%d %lf", &e2, &k2);
        if(a[e2] != 0.0)
        {
            a[e2] += k2;
            if(a[e2] == 0.0)
            {
                cnt--;
            }
        }
        else
        {
            a[e2] = k2;
            cnt++;
        }
    }

    // scanf("%d", &n1);
    // for(int i=0; i<n1; i++)
    // {
    //     scanf("%d %lf", &e1, &k1);
    //     a[e1] += k1;
    // }
    // scanf("%d", &n2);
    // for(int i=0; i<n2; i++)
    // {
    //     scanf("%d %lf", &e2, &k2);
    //     a[e2] += k2;
    // }
    // for(int i=0; i<M; i++)
    //     if(a[i]!=0.0)
    //         cnt++;

    printf("%d", cnt);
   
    for(int i=M-1; i>=0; i--)
    {
        if(a[i] != 0.0)
        {
            printf(" %d %.1f", i, a[i]);
        }
    }
    
    
    return 0;
}