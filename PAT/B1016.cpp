#include <iostream> 
#include <stdio.h> 
using namespace std;

int main()
{
    long long A, B;
    int DA, DB;
    long long PA, PB = 0;
    scanf("%lld %d %lld %d", &A, &DA, &B, &DB);
    while(A != 0)
    {
        if(DA == A%10)
        {
            PA = PA * 10 + DA;
        }
        A = A / 10;
    }
    while(B != 0)
    {
        if(DB == B%10)
        {
            PB = PB * 10 + DB;
        }
        B = B / 10;
    }
    printf("%lld\n", PA+PB);
    
    return 0;
}