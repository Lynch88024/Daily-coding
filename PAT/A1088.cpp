#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

struct Fraction
{
    long long up, down;
}a, b;

Fraction reduction(Fraction result)
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
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down + f2.up*f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down - f2.up*f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r)
{
    r = reduction(r);
    if(r.up < 0)
        printf("(");
    if(r.down == 1)
        printf("%lld", r.up);
    else if(abs(r.up) > r.down)
    {
        printf("%lld %lld/%lld", r.up/r.down, abs(r.up)%r.down, r.down);
    }
    else
    {
        printf("%lld/%lld", r.up, r.down);
    }
    if(r.up < 0)
    {
        printf(")");
    }
}
int main()
{
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a,b));
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minu(a,b));
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a,b));
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0)
        printf("Inf");
    else
        showResult(divide(a,b));

    return 0;
}