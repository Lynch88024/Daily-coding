#include <iostream> 
#include <cstdio> 
using namespace std;

int main()
{
    struct people
    {
        char name[15];
        int year, month, day;
        long long length;
    }person, old, young;
    young.length = (1814-1)*365 + (9-1)*30 + 6 -1;
    old.length = (2014-1)*365 + (9-1)*30 + 6 + 1;
    long long borden_left = (1814-1)*365 + (9-1)*30 + 6;
    long long borden_right =  (2014-1)*365 + (9-1)*30 + 6;
    int cnt = 0;

    int n = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %d/%d/%d", person.name, &person.year, &person.month, &person.day);
        person.length = 365*(person.year-1) + 30*(person.month-1) + person.day;
        if((person.length>=borden_left) && (person.length<=borden_right))
        {
            cnt++;
            if(person.length < old.length)
            {
                old = person;
            }
            if(person.length > young.length)
            {
                young = person;
            }
        }
    }
    if(cnt == 0)
        printf("0");
    else
        printf("%d %s %s", cnt, old.name, young.name);

    return 0;
}