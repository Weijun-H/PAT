#include <cstdio>
#include <algorithm>
using namespace std;
struct Mooncake{
    double store;   //库存量
    double sell;    //总售价
    double price;   //单价
}cake[1010];

bool cmp(Mooncake a, Mooncake b){
    return a.price>b.price;
}
int main() {
    int N;
    double D,profit=0;
    scanf("%d %lf",&N,&D);
    for (int i = 0; i < N; ++i) {
        scanf("%lf",&cake[i].store);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%lf",&cake[i].sell);
        cake[i].price = cake[i].sell/cake[i].store;
    }
    sort(cake,cake+N,cmp);
    for (int j = 0; j < N; ++j) {
        if (cake[j].store>D){
            profit += D*cake[j].price;
            break;
        }
        else{
            profit += cake[j].sell;
            D -= cake[j].store;
        }
    }
    printf("%.2lf",profit);
}