#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 30*30+100;
priority_queue<string, vector<string>, greater<string> > q[maxn]; 

int data_ = 1; // 测试集数量

void print_1()
{
    cout << "DATA SET " << data_ << ":" << endl << "ROOT" << endl; 
    data_ ++;
}

void print_2(int level)
{
    for(int i=0; i<level; i++)
    {
        cout << "|    ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    while(s != "#")
    {
        print_1();
        int level = 0;
        while(s != "*")
        {
            if(s[0] == 'f')
            {
                q[level].push(s);
            }
            else if(s[0] == 'd')
            {
                level++;
                print_2(level);
                cout << s << endl;
            }
            else if(s[0] == ']')
            {
                while(!q[level].empty())
                {
                    print_2(level);
                    cout << q[level].top() << endl;
                    q[level].pop();
                }
                level--;
            }
            cin >> s;
        }
        while(!q[level].empty())
        {
            print_2(level);
            cout << q[level].top() << endl;
            q[level].pop();
        }
        cout << endl;
        cin >> s;
    }
    fclose(stdin);

    return 0;
}