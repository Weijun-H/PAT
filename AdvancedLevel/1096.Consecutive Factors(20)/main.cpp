#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long LL;
int main(){
    LL n;
    scanf("%lld",&n);
    LL sqr = (LL)sqrt(1.0*n), ansI = 0, ansLen = 0;
    for (LL i = 2; i <= sqr; ++i) {         //遍历连续的第一个整数
        LL temp = 1, j=i;
        while (1){
            temp *= j;
            if(n % temp != 0)break;         //不能整除，结束计算
            if(j - i +1>ansLen){            //发现更长长度
                ansI = i;
                ansLen = j - i +1;
            }
            j++;
        }
    }
    if(ansLen == 0){                //无连续因子
        printf("1\n%lld",n);
    } else{
        printf("%lld\n",ansLen);
        for (LL i = 0; i < ansLen; i++) {
            printf("%lld",ansI+i);
            if(i<ansLen-1)printf("*");
        }
    }
}