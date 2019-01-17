#include <iostream>
#include <cstdlib> 
#include <cstring> 
using namespace std;

const int M = 110;
const int N = 25;
char s[M][N];

int main()
{
    int n = 0;
    scanf("%d", &n);
    int tag = 1;
    int weight[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[15] = {'1','0','X','9','8','7','6','5','4','3','2'};

    for(int i=0; i<n; i++)
    {
        int flag = 1;
        int sum = 0;
        scanf("%s", s[i]);
        for(int j=0; j<17; j++)
        {
            if((s[i][j]<'0')||(s[i][j]>'9'))
            {
                flag = 0;
                tag = 0;
                printf("%s\n", s[i]);
                break;
            }
            else
            {
                sum += (s[i][j] - '0') * weight[j];
            }
        }
        if(flag == 1)
        {
            if(m[sum % 11] != s[i][17])
            {
                tag = 0;
                printf("%s\n", s[i]);
            }
        }
    }
    if(tag == 1)
    {
        printf("All passed\n");
    }

    return 0;
}