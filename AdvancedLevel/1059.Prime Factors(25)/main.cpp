#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;
const int maxn = 100010;
bool isPrime(int n){
    if (n==1)return false;
    int sqr = (int)sqrt(1.0*n);
    for (int i = 2; i <=sqr  ; ++i) {
        if(n%i==0)return false;
    }
    return true;
}

int Primes[maxn];
int pNum=0;
void init(){
    for (int i = 2; i < 1000000; ++i) {
        if(isPrime(i))Primes[pNum++]=i;
    }
}
struct factor{
    int x;
    int cnt;
}fac[20];
int main() {
    init();
    int n,num=0;
    scanf("%d", &n);
    int sqr = (int)sqrt(1.0*n);
    for (int i = 0; i<pNum&&Primes[pNum] < sqr; ++i) {
        if(n%Primes[i]==0){
            fac[num].x = Primes[i];
            fac[num].cnt = 0;
            while (n%Primes[i]==0){
                fac[num].cnt++;
                n /= Primes[i];
            }
            num++;
        }
    }
    if (n!=1){
        fac[num].x=n;
        fac[num].cnt=1;
    }
    for (int j = 0; j < num; ++j) {
        if (fac[j].cnt>1){
            cout<<fac[j].x<<"^"<<fac[j].cnt;
        } else cout<<fac[j].x;
        if(j<num-1)cout<<"*";
    }
}