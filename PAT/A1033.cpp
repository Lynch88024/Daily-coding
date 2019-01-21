#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 510;

struct station 
{
    double price;
    double distance;
}sta[N];

bool cmp(station a, station b);

int main()
{
    int n = 0;
    double Cmax, D, Davg = 0.0;
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
    double dis_max = Cmax * Davg;
    for(int i=0; i<n; i++)
    {
        scanf("%lf %lf", &sta[i].price, &sta[i].distance);
    }
    sta[n].price = 0.0;
    sta[n].distance = D;
    sort(sta, sta+n, cmp);

    if(sta[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00");    
    }
    else
    {
        double price_sum = 0;
        double tank_start = 0;
        int start = 0;
        while(start < n)
        {
            int k = -1;
            double price_min = 100000000000;
            for(int i=start+1; i<=n; i++)
            {
                if(sta[i].distance-sta[start].distance <= dis_max)
                {
                    if(sta[i].price < price_min)
                    {
                        price_min = sta[i].price;
                        k = i;
                        if(sta[i].price < sta[start].price)
                        {
                            break;
                        }
                    }
                }
            }
            if(k == -1)
            {
                break;
            }
            double need = (sta[k].distance - sta[start].distance) / Davg;
            if(sta[k].price < sta[start].price)
            {
                if(tank_start < need)
                {
                    price_sum += (need - tank_start) * sta[start].price;
                    tank_start = 0.0;
                }
                else
                {
                    tank_start -= need;
                }
            }
            else
            {
                price_sum += (Cmax -tank_start) * sta[start].price;
                tank_start = Cmax - need;
            }
            start = k;
        }
        if(start == n)
        {
            printf("%.2f\n", price_sum);
        }
        else
        {
            printf("The maximum travel distance = %.2lf", sta[start].distance+dis_max);
        }
    }

    // double price_sum = 0;
    // double distance_sum = 0;
    // int start = 0;
    // while(start != n)
    // {
    //     int flag_distance, flag_price = 0;
    //     int min_station = start + 1;
    //     for(int i=start; i<=n; i++)
    //     {
    //         if(sta[i].distance <= dis_max)
    //         {
    //             flag_distance = 1;
    //             if(sta[i].price <= sta[start].price)
    //             {
    //                 flag_price = 1;
    //                 price_sum += (sta[i].distance - sta[start].distance) / Davg * sta[i].price;
    //                 distance_sum += (sta[i].distance - sta[start].distance);
    //                 start = i;
    //                 break;
    //             }
    //             else
    //             {

    //                 if(sta[i].price < )
    //             }
    //         }
    //     }
    //     if(flag_distance == 0)
    //     {
    //         printf("The maximum travel distance = %.2lf", distance_sum);
    //         break;
    //     }
    //     if(flag_price == 0)
    //     {
    //         price_sum += Cmax * sta[start].price;
    //     }
        
    // }

    return 0;
}

bool cmp(station a, station b)
{
    return a.distance < b.distance;
}