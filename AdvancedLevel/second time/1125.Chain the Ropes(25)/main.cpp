#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 10005;
int main() {
    double res;
    int n;
    double a[maxn];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    res = a[0];
    for (int i = 1; i < n; ++i) {
        res = ((res+a[i])/2);
    }
    printf("%d",int(res));
}