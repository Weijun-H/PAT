#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int main() {
    int n,A[maxn],dp[maxn],s[maxn];
    bool flag = false;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        if (temp>0)flag = true;

        A[i] = temp;
    }
    if (!flag){
        printf("0 %d %d",A[0],A[n-1]);
        return 0;
    }
    dp[0] = A[0];
    s[0]=0;
    for (int i = 1; i <n ; ++i) {
        if(A[i]>dp[i-1]+A[i]){dp[i]=A[i];s[i]=i;}
        else {
            dp[i]=dp[i-1]+A[i];
            s[i] = s[i-1];
        }
    }
    int temp = -1;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if(dp[i]>temp){
            temp = dp[i];
            k = i;
        }
    }
    printf("%d %d %d",temp,A[s[k]],A[k]);
}