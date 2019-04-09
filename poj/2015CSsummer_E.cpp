#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 10010;
string str[maxn];

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    cin >> str[0];
    ans += str[0].size();
    for(int i=1; i<n; i++)
    {
        cin >> str[i];
        int len1 = str[i-1].size();
        int len2 = str[i].size();
        int len = min(len1, len2);  
        int common = 0;
        for(int j=0; j<len; j++)
        {
            if(str[i-1][j] == str[i][j])
            {
                common++;
            }
            else 
            {
                break;
            }
        }
        if(common == 0)
        {
            ans += (len2 + 1);
        }
        else 
        {
            ans += (len2 - common + 1);
        }
    }
    cout << ans;
    // fclose(stdin);

    return 0;
}   