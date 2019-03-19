// 分数的四则运算

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Fraction
{
    long long up;
    long long down;
};

long long gcd(long long a, long long b) // 最大公约数
{
    if(b == 0)
    {
        return a;
    }
    else 
    {
        return gcd(b, a%b); 
    }
}

long long lcm(long long a, long long b) // 最小公倍数
{
    long long d = gcd(a, b);
    return a/d*b;
}

Fraction reduction(Fraction result) // 分数的化简(三条规则)
{
    if(result.down < 0)
    {
        result.down = -result.down;
        result.up = -result.up;
    }
    if(result.up == 0)
    {
        result.down = 1;
    }
    else
    {
        long long d = gcd(result.up, result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}

/*********************分数的加法*********************/
Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down + f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result); // 返回化简后的结果
}

/*********************分数的减法*********************/
Fraction sub(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down - f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

/*********************分数的乘法*********************/
Fraction multi(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/*********************分数的除法*********************/
Fraction divide(Fraction f1, Fraction f2) // 需要保证除数不为0 -> 要判断f2.up是否为0
{
    Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
}

/*********************分数输出*********************/
void print(Fraction r)
{
    r = reduction(r); // 先化简
    if(r.down == 1) // 整数
    {
        printf("%lld", r.up);
    }
    else if(abs(r.up) > abs(r.down)) // 带分数
    {
        printf("%d %d/%d", r.up/r.down, abs(r.up)%r.down, r.down);
    }
    else // 真分数
    {
        printf("%d/%d", r.up, r.down);
    }
}

