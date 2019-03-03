// 简易计算器

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    double num;
    char op;
    bool flag;
};

string str; // 输入字符串
stack<Node> s; // 符号栈
queue<Node> q; // 数字队列
map<char, int> op; // 符号优先级映射

void change() // 中缀表达式 -> 后缀表达式
{
    Node temp;
    for(int i=0; i<str.length(); )
    {
        if(str[i]>='0' && str[i]<='9')
        {
            temp.flag = true; // 数字
            temp.num = str[i] - '0';
            i++;
            while(i<str.length() && str[i]>='0' && str[i]<='9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag = false; // 符号
            temp.op = str[i];
            while(!s.empty() && op[str[i]]<=op[s.top().op]) // 读入符号优先级 ≤ 栈顶符号优先级
            {
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()) // 操作符栈中仍有操作符，全部弹出
    {
        q.push(s.top());
        s.pop();
    }
}

double cal() // 计算后缀表达式
{
    double temp1, temp2;
    Node cur, temp;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(cur.flag == true) // 操作数
        {
            s.push(cur);
        }
        else // 操作符
        {
            temp2 = s.top().num;
            s.pop(); 
            temp1 = s.top().num;
            s.pop(); 
            temp.flag = true;
            if(cur.op == '+')
                temp.num = temp1 + temp2;
            else if(cur.op == '-')
                temp.num = temp1 - temp2;
            else if(cur.op == '*')
                temp.num = temp1 * temp2;
            else 
                temp.num = temp1 / temp2;
            s.push(temp);
        }
    }

    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    // getline(cin, str);
    // for(string::iterator it = str.end(); it != str.begin(); it--)
    // {
    //     if(*it == ' ')
    //     {
    //         str.erase(it);
    //     }
    // }
    // while(!s.empty()) // 初始化栈
    // {
    //     s.pop();
    // }
    // change(); // 转换
    // printf("%.2f\n", cal());
    while(getline(cin, str), str != "0") 
    {
        for(string::iterator it = str.end(); it != str.begin(); it--)
        {
            if(*it == ' ')
            {
                str.erase(it);
            }
        }
        while(!s.empty()) // 初始化栈
        {
            s.pop();
        }
        change(); // 转换
        printf("%.2f\n", cal());    
    }

    return 0;
}