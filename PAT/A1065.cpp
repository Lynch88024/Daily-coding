#include <iostream> 
#include <cstdio> 
using namespace std; 

int main()
{
    int t = 0;
    scanf("%d", &t);
    long long a, b, c = 0;
    long long res = 0;
    for(int i=0; i<t; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        res = a + b;
        if(a>0 && b>0 && res<0)
        {
            printf("Case #%d: true\n", i+1);
        }
        else if(a<0 && b<0 && res>=0)
        {
            printf("Case #%d: false\n", i+1);
        }
        else if(res > c)
        {
            printf("Case #%d: true\n", i+1);
        }
        else
        {
            printf("Case #%d: false\n", i+1);
        }
    }   

    return 0;
}