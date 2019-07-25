#include <cstdio>
using namespace std;

int main() {
    int G,K,S;
    int G1,K1,S1;
    int NG,NK,NS;
    scanf("%d.%d.%d %d.%d.%d",&G,&K,&S,&G1,&K1,&S1);
    NS = S+S1;
    if (NS>=29){
        NK = NS/29;
        NS %= 29;
    }

    NK += K+K1;
    if (NK>=17){
        NG = NK/17;
        NK %= 17;
    }
    NG += G+G1;
    printf("%d.%d.%d",NG,NK,NS);


}