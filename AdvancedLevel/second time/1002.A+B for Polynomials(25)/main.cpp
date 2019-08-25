#include <cstdio>
#include <string>
using namespace std;
const int maxn = 10005;
int main() {
    double a[maxn];
    fill(a,a+maxn,0);
    int k,cnt=0;
    int index;
    double num;
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {

        scanf("%d %lf",&index,&num);
        a[index]=num;
    }
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %lf",&index,&num);
        a[index] += num;
    }

    for (int j = maxn-1; j >=0 ; --j) {
        if(a[j]!=0){
            cnt++;
        }
    }
    printf("%d",cnt);

    for (int j = maxn-1; j >=0 ; --j) {
        if(a[j]!=0){
            printf(" %d %.1lf",j,a[j]);

        }
    }
    return 0;
}

