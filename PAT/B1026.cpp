#include <iostream> 
#include <stdio.h> 
#include <math.h>
using namespace std;

int main()
{
    int C1, C2, C;
    int t = 0;
    scanf("%d %d", &C1, &C2);
    C = C2 - C1;
    int x = C / 100;
    double s = C / 100.0;
    double s1 = s - floor(s);
    if(s1-0.5<0.0)
    {
        t = x;
    }  
    else
    {
        t = x + 1;
    }
    
    int hh = t / 3600;
    int mm = t % 3600 / 60;
    //int mm = (t - 3600 * hh) / 60;
    //int ss = t - 3600 * hh - 60 * mm;
    int ss = t % 60;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}