#include <iostream> 
#include <cstdio> 
using namespace std;

int number[105] = {0};

int main()
{   
    int n = 0;
    scanf("%d", &n);
    int score = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &score);
        number[score]++;
    }
    int k = 0;
    scanf("%d", &k);
    for(int i=0; i<k; i++)
    {
        scanf("%d", &score);
        printf("%d", number[score]);
        if(i != k-1)
        {
            printf(" ");
        }
    }

    return 0;
}