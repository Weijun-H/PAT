#include <cstdio>
#include <math.h>
using namespace std;
const int maxn = 100010;
int distance[maxn]={0};
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int d;
        scanf("%d",&d);
        distance[i]=distance[i-1]+d;
    }
    int total_distance = distance[n];
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        int a,b,d1,d2;
        scanf("%d%d",&a,&b);
        if(a>b){
            d1 = distance[a-1]-distance[b-1];
        }else d1 = distance[b-1]-distance[a-1];
        d2 = total_distance-d1;
        if(d1>d2){
            printf("%d\n",d2);
        }
        else printf("%d\n",d1);
    }

}