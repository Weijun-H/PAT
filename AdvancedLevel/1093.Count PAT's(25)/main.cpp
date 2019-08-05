#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
const int maxn = 100005;
int main() {
    char s[maxn];
    cin.getline(s,maxn);
    int n = strlen(s);
    int leftNum[maxn]= {0};
    for (int i=0; i<n; i++){
        if(n>0) leftNum[i] = leftNum[i-1];
        if (s[i]=='P')leftNum[i]++;
    }
    int ans=0, rightNum=0;
    for (int j = n-1; j >= 0; --j) {
        if(s[j]=='T')rightNum++;
        if (s[j]=='A')ans = (ans+leftNum[j]*rightNum)%MOD;
    }
    printf("%d",ans);
}