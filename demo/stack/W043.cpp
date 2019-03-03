// 括号匹配问题

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 110;
char input[maxn], output[maxn];
int hashtable[maxn];
stack<char> st;

int main()
{
    scanf("%s", input);
    int len = strlen(input);
    for(int i=0; i<len; i++)
    {
        output[i] = ' ';
    }
    output[len] = '\0';
    int count = 0;
    for(int i=0; i<len; i++)
    {
        if(input[i] == '(')
        {
            output[i] = '$';
            st.push(input[i]);
            hashtable[++count] = i; 
        }
        else if(input[i] == ')')
        {
            if(!st.empty())
            {
                output[hashtable[st.size()]] = ' ';
                st.pop();
                count--;
            }
            else
            {
                output[i] = '?';
            }
        }
       
    }
    printf("%s", output);

    return 0;
}