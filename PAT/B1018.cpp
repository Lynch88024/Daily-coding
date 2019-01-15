#include <iostream> 
#include <stdio.h> 
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char a, b;
    int win_A[5] = {0}; // 0~B 1~C 2~J
    int equ_A[5] = {0};
    int fail_A[5] = {0};
    int win_B[5] = {0};
    int equ_B[5] = {0};
    int fail_B[5] = {0};
    char show[5] = {'B', 'C', 'J'};

    for(int i=0; i<n; i++)
    {
        getchar();
        scanf("%c %c", &a, &b);
        if((a=='C')&&(b=='J'))
        {
            win_A[1]++;
            fail_B[2]++;
        }
        else if((a=='J')&&(b=='B'))
        {
            win_A[2]++;
            fail_B[0]++;
        }
        else if((a=='B')&&(b=='C'))
        {
            win_A[0]++;
            fail_B[1]++;
        }
        else if((b=='C')&&(a=='J'))
        {
            win_B[1]++;
            fail_A[2]++;
        }
        else if((b=='J')&&(a=='B'))
        {
            win_B[2]++;
            fail_A[0]++;
        }
        else if((b=='B')&&(a=='C'))
        {
            win_B[0]++;
            fail_A[1]++;
        }
        else if((a=='B')&&(b=='B'))
        {
            equ_A[0]++;
            equ_B[0]++;
        }
        else if((a=='C')&&(b=='C'))
        {
            equ_A[1]++;
            equ_B[1]++;
        }
        else if((a=='J')&&(b=='J'))
        {
            equ_A[2]++;
            equ_B[2]++;
        }
    }

    int winA = win_A[0] + win_A[1] + win_A[2];
    int equA = equ_A[0] + equ_A[1] + equ_A[2];
    int failA = fail_A[0] + fail_A[1] + fail_A[2];
    int winB = win_B[0] + win_B[1] + win_B[2];
    int equB = equ_B[0] + equ_B[1] + equ_B[2];
    int failB = fail_B[0] + fail_B[1] + fail_B[2];

    printf("%d %d %d\n", winA, equA, failA);
    printf("%d %d %d\n", winB, equB, failB);

    int max_A = 0;
    int max_B = 0;
    for(int i=0; i<3; i++)
    {
        if(win_A[i] > win_A[max_A])
        {
            max_A = i;
        }
        if(win_B[i] > win_B[max_B])
        {
            max_B = i;
        }
    }
    printf("%c %c", show[max_A], show[max_B]);

    return 0;
}