#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool cmp(long a, long b){
    return a<b;
}
int main() {
    long long n,p,num[maxn];
    cin>>n>>p;
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
    }
    if(n==0)cout<<"0";
    sort(num,num+n,cmp);
    int i=0,j=0;
    int max = -1;
    while (j<n){
        if(num[i]*p>=num[j]){
            if(max<=j-i+1){
                max = j-i+1;
            }
            j++;
        } else i++;
    }
    cout<<max;
}