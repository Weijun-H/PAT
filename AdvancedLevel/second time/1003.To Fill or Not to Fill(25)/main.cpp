#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 30005;
struct Station{
    double distance;
    double price;
}station[maxn];

bool cmp_D(Station a, Station b){
    return a.distance<b.distance;
}
int main() {
    double Cmax,distance,Davg,ans=0;
    int n;
    scanf("%lf%lf%lf%d",&Cmax,&distance,&Davg,&n);
    double Dmax = Davg*Cmax;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf",&station[i].price, &station[i].distance);
    }
    int now = 0;
    float has_go=0.0;
    sort(station,station+n,cmp_D);
    if(station[0].distance!=0)printf("The maximum travel distance = 0.00");
    int idx = now;


    while (has_go!=distance) {
        float temp = station[now].price;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (Dmax + has_go >= station[i].distance && station[i].distance >= has_go) {
                if (station[i].price <= temp) {
                    temp = station[i].price;
                    flag = true;
                    idx = i;
                }
            }
        }
        if (!flag) {
            temp = 1e10;
            idx = -1;
            for (int i = 0; i < n; ++i) {
                if (Dmax + has_go >= station[i].distance && station[i].distance >= has_go) {
                    if (station[i].price <= temp) {
                        idx = i;
                        temp = station[i].price;
                    }
                }
            }
        }
        if (idx == -1) {
            printf("The maximum travel distance = %0.2f", has_go + Dmax);
            return 0;
        }
        ans += (station[idx].distance - has_go) * station[now].price;
        has_go = station[idx].distance;
        now = idx;
        if(now==n-1){
            if(has_go+Dmax>=distance){
                ans += (distance-has_go)*station[now].price;
                has_go = distance;
            } else {
                printf("The maximum travel distance = %0.2f", has_go + Dmax);
                return 0;
            }
        }
        printf("distance %lf\n",idx);
    }
    printf("%0.2f",ans);
}