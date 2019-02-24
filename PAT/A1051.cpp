#include <cstdio> 
#include <iostream>
#include <stack> 
using namespace std;

const int maxn = 1010;
int arr[maxn];
stack<int> st;

int main()
{
    int m, n, k = 0;
    scanf("%d %d %d", &m, &n, &k);

    for(int i=0; i<k; i++)
    {
        while(!st.empty())
        {
            st.pop();
        }
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &arr[j]);
        }
        bool flag = true;
        int cur = 1;

        for(int j=1; j<=n; j++)
        {
            st.push(j);
            if(st.size() > m)
            {
                flag = false;
                break;
            }
            else
            {
                while(!st.empty() && st.top() == arr[cur]) // 一定要先判断空！
                {
                    st.pop();
                    cur++;
                }
            }
        }

        if(st.empty() && flag==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}