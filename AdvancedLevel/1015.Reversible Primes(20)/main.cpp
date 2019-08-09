#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n) {                   //判断素数
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {         //一直输入
        if(n < 0) break;                    //为负数结束
        scanf("%d", &d);
        if(isprime(n) == false) {           //本身是否为素数
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        do{
            arr[len++] = n % d;
            n = n / d;
        }while(n != 0);
        for(int i = 0; i < len; i++)
            n = n * d + arr[i];             //反向输出
        printf("%s", isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}