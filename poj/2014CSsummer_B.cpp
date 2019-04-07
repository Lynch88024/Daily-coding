#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    stack<int> s;
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
        {
            s.push(i);
        }
        else if(str[i] == ')')
        {
            cout << s.top() << " " << i << endl;
            s.pop();
        }
    }

    return 0;
}