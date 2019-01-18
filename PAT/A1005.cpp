#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 110;

int main()
{
    char num[M];
    scanf("%s", num);
    int len = strlen(num);
    int sum = 0;
    for(int i=0; i<len; i++)
    {
        sum += (num[i] - '0');
    }
    //printf("%d",sum);
    char show[15][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(sum == 0)
        printf("zero");
    else
    {
        int a[M] = {0};
        int i = 0;
        while(sum != 0)
        {
            a[i++] = sum % 10;
            sum /= 10;
        }
        printf("%s", show[a[i-1]]);
        for(int j=i-2; j>=0; j--)
        {
            printf(" %s", show[a[j]]);
        }
    }

    return 0;
}