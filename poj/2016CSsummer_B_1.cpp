#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 110;
char str[maxn];
stack<char> s;

int main()
{
    gets(str);
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i] != ' ')
        {
            s.push(str[i]);
        }
        else 
        {
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}