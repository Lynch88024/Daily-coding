#include <iostream> 
#include <cstdio>
using namespace std;

const int M = 1010;

int main()
{
    struct student
    {
        long long number;
        int examseat;
    } testseat[M];

    int n = 0;
    scanf("%d", &n);
    long long num = 0;
    int seat_t, seat_e = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%lld %d %d", &num, &seat_t, &seat_e);
        testseat[seat_t].number = num;
        testseat[seat_t].examseat = seat_e;
    }
    int m = 0;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &seat_t);
        printf("%lld %d\n", testseat[seat_t].number, testseat[seat_t].examseat);
    }

    return 0;
}