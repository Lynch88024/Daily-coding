#include <iostream> 
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int N = 10010;
string str[N];

bool cmp(string a, string b);

int main()
{
    int n=0; 
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str[i];
    }
    sort(str, str+n, cmp);
    string ans;
    for(int i=0; i<n; i++)
    {
        ans += str[i];
    }
    while(ans.length()!=0 && ans[0]=='0')
    {
        ans.erase(ans.begin());
    }
    if(ans.length() == 0)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
    
    return 0;
}

bool cmp(string a, string b)
{
    return a+b < b+a;
}