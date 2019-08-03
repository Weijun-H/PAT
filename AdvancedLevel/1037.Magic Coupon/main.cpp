#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100010;

bool cmp(int a, int b) {return a>b;}
bool cmp1(int a, int b) {return a<b;}

int main() {
    int NC, NP;
    int NC_P[maxn/2], NC_N[maxn/2], NP_P[maxn/2], NP_N[maxn/2];
    int CP_N=0, PP_N=0,CN_N=0, PN_N=0;//CP_N is the number of the NC_P
    scanf("%d", &NC);
    for (int i = 0; i < NC; ++i) {
        int a;
        scanf("%d",&a);

        if (a>0) {NC_P[CP_N++] = a;}
        else NC_N[CN_N++] = a;
    }

    scanf("%d", &NP);
    for (int i = 0; i < NP; ++i) {
        int a;
        scanf("%d",&a);
        if (a>0){ NP_P[PP_N++] = a;}
        else {NP_N[PN_N++] = a;}
    }
    sort(NC_P,NC_P+CP_N,cmp);       //排序
    sort(NC_N,NC_N+NC-CP_N);

    sort(NP_P,NP_P+PP_N,cmp);
    sort(NP_N,NP_N+NP-PP_N);



    int ans = 0;
    for (int j = 0; j < CP_N && j< PP_N; ++j) {
        ans +=  NC_P[j]* NP_P[j];
    }

    for (int j = 0; j < NC-CP_N && j< NP-PP_N; ++j) {
        ans +=  NC_N[j]* NP_N[j];
    }
    printf("%d",ans);


}