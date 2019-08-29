#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
struct Mooncake{
    float need;
    float total_price;
    float unit_price;
}mooncake[maxn];
bool cmp(Mooncake a, Mooncake b){
    return a.unit_price>b.unit_price;
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>mooncake[i].need;
    }
    for (int i = 0; i < n; ++i) {
        cin>>mooncake[i].total_price;
        mooncake[i].unit_price = mooncake[i].total_price/mooncake[i].need;
    }
    sort(mooncake,mooncake+n,cmp);
    float res=0;
    for (int i = 0; i < n; ++i) {
        if(m>mooncake[i].need){
            res += mooncake[i].total_price;
            m -= mooncake[i].need;
        } else if(m<=mooncake[i].need){
            res += m*mooncake[i].unit_price;
            break;
        }

    }
    printf("%0.2f",res);
}