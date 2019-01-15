#include <iostream> 
#include <stdio.h> 
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int A_han, B_han = 0;
    int A_hua, B_hua = 0;
    int A_he = 0;
    int B_he = 0;
    for(int i=0; i<N; i++)
    {
        
        scanf("%d %d %d %d", &A_han, &A_hua, &B_han, &B_hua);
        if((A_hua == A_han+B_han)&&(B_hua != A_han+B_han))
        {
            B_he++;
        }
        else if((B_hua == A_han+B_han)&&(A_hua != A_han+B_han))
        { 
            A_he++;
        }
    }
    printf("%d %d\n", A_he, B_he);

    return 0;
}