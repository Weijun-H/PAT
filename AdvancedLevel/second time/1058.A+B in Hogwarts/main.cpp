#include <cstdio>
using namespace std;
int a[3],b[3];
int base[3]={29,17};
int main() {
    scanf("%d.%d.%d",&a[2],&a[1],&a[0]);
    scanf("%d.%d.%d",&b[2],&b[1],&b[0]);
    int temp=0;
    for (int i = 0; i < 3; ++i) {
        a[i] += b[i]+temp;
        if(i!=2) {
            temp = a[i] / base[i];
            a[i] %= base[i];
        }
    }
    for (int j = 2; j >= 0 ; --j) {
        printf("%d",a[j]);
        if(j!=0)printf(".");
    }

}