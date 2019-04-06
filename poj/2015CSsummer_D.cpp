#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> m, f;

bool cmp(double a, double b)
{
    return a > b;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char gender[10];
        double height;
        scanf("%s %lf", gender, &height);
        if(strcmp(gender, "male") == 0)
        {
            m.push_back(height);
        }
        else 
        {
            f.push_back(height);
        }
    }
    sort(m.begin(), m.end());
    sort(f.begin(), f.end(), cmp);
    for(int i=0; i<m.size(); i++)
    {
        printf("%.2lf ", m[i]);
    }
    for(int i=0; i<f.size(); i++)
    {
        printf("%.2lf", f[i]);
        if(i != f.size()-1)
        {
            printf(" ");
        }
    }
    // fclose(stdin);

    return 0;
}