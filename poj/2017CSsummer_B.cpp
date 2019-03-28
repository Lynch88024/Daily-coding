#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1010;
char str[maxn];
vector<char> ch;
vector<int> cn; 

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] += 32;
        }
    }
    str[len] = '\0';
    int cnt = 1;
    for(int i=0; i<len-1; i++)
    {
        if(str[i+1] == str[i])
        {
            cnt++;
        }
        else if(str[i+1] != str[i])
        {
            ch.push_back(str[i]); 
            cn.push_back(cnt);
            cnt = 1;
        }
    }
    ch.push_back(str[len-1]); // 最后一次加入的字符串不会在循环体中被加入
    cn.push_back(cnt);
    for(int i=0; i<ch.size(); i++)
    {
        printf("(%c,%d)", ch[i], cn[i]);
    }

    return 0;
}