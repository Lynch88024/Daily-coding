    #include <iostream> 
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    using namespace std;

    const int N = 100010;

    struct people 
    {
        char name[10];
        int age;
        int worth;
    }person[N];

    bool cmp(people a, people b);

    int main()
    {
        int n, k = 0;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%s %d %d", person[i].name, &person[i].age, &person[i].worth);
        }
        sort(person, person+n, cmp);
        int m, left, right = 0;
        for(int i=0; i<k; i++)
        {
            int cnt = 0;
            scanf("%d %d %d", &m, &left, &right);
            printf("Case #%d:\n", i+1);
            for(int j=0; j<n; j++)
            {
                if((person[j].age>=left) && (person[j].age<=right))
                {
                    cnt++;
                    printf("%s %d %d\n", person[j].name, person[j].age, person[j].worth);
                    if(cnt == m)
                    {
                        break;
                    }
                }
            }
            if(cnt == 0)
            {
                printf("None\n");
            }
        }

        return 0;
    }

    bool cmp(people a, people b)
    {
        if(a.worth != b.worth)
            return a.worth > b.worth;
        else if(a.age != b.age)
            return a.age < b.age;
        else
            return strcmp(a.name, b.name) < 0;
    }