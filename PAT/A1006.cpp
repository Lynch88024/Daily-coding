#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
    struct work 
    {
        char id[20];
        int hh_c, mm_c, ss_c;
        int hh_l, mm_l, ss_l; 
        long long time_c, time_l;
    }worker, first, last;
    first.time_c = 24*3600;
    last.time_l = 0;

    int n = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", worker.id, &worker.hh_c, &worker.mm_c, &worker.ss_c, &worker.hh_l, &worker.mm_l, &worker.ss_l);
        worker.time_c = 3600*worker.hh_c + 60*worker.mm_c + worker.ss_c;
        worker.time_l = 3600*worker.hh_l + 60*worker.mm_l + worker.ss_l;
        if(worker.time_c < worker.time_l)
        {
            if(worker.time_c < first.time_c)
            {
                first = worker;
            }
            if(worker.time_l > last.time_l)
            {
                last = worker;
            }
        }
    }
    printf("%s %s", first.id, last.id);

    return 0;
}