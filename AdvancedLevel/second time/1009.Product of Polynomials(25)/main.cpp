#include <cstdio>
#include <string>
using namespace std;
const int maxn = 1010;
double a[maxn],b[maxn],res[maxn];
int main() {
    int k1,k2,index;
    fill(a,maxn+a,0);
    fill(b,b+maxn,0);
    double c;
    scanf("%d",&k1);
    for (int i = 0; i < k1; ++i) {
        scanf("%d%lf",&index,&c);
        a[index] = c;
    }
    scanf("%d",&k2);
    for (int i = 0; i < k2; ++i) {
        scanf("%d%lf",&index,&c);
            for (int k = maxn-1; k >= 0 ; --k) {
                if(a[k]!=0){
                    b[k+index]+=c*a[k];
                }
            }
    }
    int cnt=0;
    for (int k = maxn-1; k >= 0 ; --k) {
        if(b[k]!=0){
            cnt++;
        }
    }
    printf("%d",cnt);

    for (int k = maxn-1; k >= 0 ; --k) {
        if(b[k]!=0)printf(" %d %.1lf",k,b[k]);
    }
}