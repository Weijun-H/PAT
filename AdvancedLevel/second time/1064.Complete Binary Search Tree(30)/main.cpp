#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int n,num[maxn],CBT[maxn],idx=0;
void inOrder(int root){
    if(root>n)return;
    inOrder(2*root);
    CBT[root]=num[idx++];
    inOrder(2*root+1);
}
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
    }
    sort(num,num+n);
    inOrder(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d",CBT[i]);
        if(i!=n-1)printf(" ");
    }
}