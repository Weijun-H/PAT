#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int rides[maxn];

int main() {
    int n;
    int cnt = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>rides[i];
    }
    sort(rides,rides+n,greater<int>());
    for (int i = 0; i <n; ++i) {
        if(i+1<rides[i]){
            cnt++;
        }
    }

    cout<<cnt;
}