#include <cstdio>
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d",&n);
    LL a,b,c,res;
    for (int i = 0; i < n; ++i) {
        bool flag= false;
        scanf("%lld %lld %lld",&a,&b,&c);
        res = a+b;
        if(a>0&&b>0&&res<=0)flag= true;
        else if (a<0&&b<0&&res>=0)flag = false;
        else if(res-c>0)flag = true;
        else flag = false;
        printf("Case #%d: ",i+1);
        //printf("%d %d %d",a,b,c);
        if (flag== true)printf("true\n");
        else printf("false\n");
    }
}