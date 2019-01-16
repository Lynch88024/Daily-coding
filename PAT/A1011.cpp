#include <iostream>
#include <cstdio> 
using namespace std;

int main()
{
    char s[5] = {'W', 'T', 'L'};
    int max[5] = {0};
    double a[5] = {0.0};
    double x[5] = {0.0};
    double result = 0.0;
    
    for(int i=0; i<3; i++)
    {
        scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
        max[i] = 0;
        for(int j=0; j<3; j++)
        {
            if(a[j] > a[max[i]])
            {
                max[i] = j;
            }
        }
        x[i] = a[max[i]];
    }

    result = (x[0]*x[1]*x[2]*0.65-1)*2;
    printf("%c %c %c %.2f", s[max[0]], s[max[1]], s[max[2]], result);

    return 0;
}