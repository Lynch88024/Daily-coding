#include <iostream>
#include <stdio.h> 
using namespace std;

const int MM = 110;
int a[MM];

int main()
{
    int N, M = 0;
    scanf("%d %d", &N, &M);
    M = M % N;

    for(int i=0; i<N; i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    {
        scanf("%d ", &a[i]);
    }
    for(int i=N-M; i<N; i++)
    {
        printf("%d ", a[i]);
    }
    for(int i=0; i<N-M-1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d", a[N-M-1]);

    return 0;
}

