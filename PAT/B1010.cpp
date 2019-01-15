    #include <iostream> 
    #include <cstdio> 
    using namespace std;

    const int M = 1010;
    int a[M] = {0};

    int main()
    {
        int k, e = 0;
        int cnt = 0;
        while(scanf("%d %d", &k, &e) != EOF)
        {
            a[e] = k;
            if(e != 0)
                cnt++;
        }
        if(cnt == 0)
            printf("0 0");
        else
        {
            for(int i=M-1; i>=1; i--)
            {
                if(a[i] != 0)
                {
                    printf("%d %d", a[i]*i, i-1);
                    cnt--;
                    if(cnt != 0)
                        printf(" ");
                }
            }
        }
        return 0;
    }