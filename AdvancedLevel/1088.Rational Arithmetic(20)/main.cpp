#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int t1, int t2){
    return t2 == 0? t1 :gcd(t2,t1%t1);
}
struct Fraction{
    int up;
    int down;
}frac[2];
int main() {
    scanf("%d/%d %d/%d",&frac[0].up,&frac[0].down,&frac[1].up,&frac[1].down);
    frac[0].
}