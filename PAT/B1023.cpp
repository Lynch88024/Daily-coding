#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

int hashtable[10] = {0};

int main()
{
    for(int i=0; i<10; i++)
    {
        scanf("%d", &hashtable[i]);
    }
    for(int i=1; i<10; i++)
    {
        if(hashtable[i] > 0)
        {
            printf("%d", i);
            hashtable[i]--;
            break;
        }
    }
    for(int i=0; i<10; i++)
    {
        while(hashtable[i] > 0)
        {
            printf("%d", i);
            hashtable[i]--;
        }
    }

    return 0;
}