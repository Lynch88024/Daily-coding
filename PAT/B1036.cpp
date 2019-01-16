#include <iostream> 
#include <cstdio> 
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    char c;
    scanf("%d %c", &n, &c);
    int col = n;
    int row = (int)round(n/2.0);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if((i==0)||(j==0)||(i==row-1)||(j==col-1))
            {
                printf("%c", c);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}