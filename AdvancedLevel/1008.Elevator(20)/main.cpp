#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans = 0;
    int now=0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        if(i==0) {ans += 6*a + 5;now=a;}
        else{
            if (now-a>0){ans += 4*(now-a) +5;now=a;}//下降;
            else{ans += 6*(a-now)+5;now=a;}
        }
    }
    cout<<ans;
}