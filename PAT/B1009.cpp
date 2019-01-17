#include <iostream> 
#include <cstdio> 
using namespace std;

const int M = 90;

int main()
{
    int num = 0;
    char ans[M][M];
    while(scanf("%s", ans[num]) != EOF)
    {
        num++;
    }
    for(int i=num-1; i>=0; i--)
    {
        printf("%s", ans[i]);
        if(i>0)
            printf(" ");
    }

    return 0;
}





/*无法通过所有测试点*/
// #include <iostream>
// #include <cstdio> 
// #include <cstring>
// using namespace std;

// const int M = 90;

// int main()
// {
//     char s[M];//= "    hello world here i come";
//     scanf("%s", s);
//     char x[M][M];
//     int len = strlen(s);
//     int j = 0;
//     int k = 0;
//     int flag = 0;
//     int cnt = 0;
//     if(len == 0)
//     {
//         int xx[M];
//         xx[0] = '\0';
//         printf("%s", xx);
//     }
//     else
//     {
//         for(int i=0; i<len; i++)
//         {
//             if((s[i]==' ')&&(flag==1))
//             {
//                 x[j][k] = '\0';
//                 j++;
//                 k = 0;
//             }
//             else if(s[i] != '\0')
//             {
//                 flag = 1;
//                 x[j][k++] = s[i];
//             }
//             else
//             {
//                 cnt++;
//                 continue;
//             }
//         }
//         for(int i=j; i>=0; i--)
//         {
//             printf("%s", x[i]);
//             if(i>0)
//                 printf(" ");
//         }
//         for(int i=0; i<cnt; i++)
//         {
//             printf(" ");
//         }
//     }  

//     return 0;
// }