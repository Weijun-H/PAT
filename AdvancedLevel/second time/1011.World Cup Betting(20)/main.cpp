#include <cstdio>
using namespace std;
char choice[3]={'W','T','L'};
int main() {
    int a[3];
    double res=1;
    double max_temp;
    for (int i = 0; i < 3; ++i) {
        int pc=0;
        for (int j = 0; j < 3; ++j) {
            double temp;
            scanf("%lf",&temp);
            if(j==0)max_temp=temp;
            if(max_temp<temp){
                max_temp=temp;
                pc=j;
            }
        }
        res*=max_temp;
        printf("%c ",choice[pc]);
    }
    printf("%.2lf",(res*0.65-1)*2);
}