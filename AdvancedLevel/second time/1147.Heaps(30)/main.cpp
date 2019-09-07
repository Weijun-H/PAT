#include <iostream>
using namespace std;
const int maxn = 105;
int n,datas[maxn],num=0;
void preorder(int root){
    if(root>=n)return;
    preorder(root*2+1);
    preorder(root*2+2);
    printf("%d",datas[root]);
    if(num++!=n-1)printf(" ");
}
void judge(){
    int isMAX=1,isMIN=1;
    for (int i = 2; i <n ; ++i) {
        if(datas[(i-1)/2]>datas[i])isMIN=0;
        if(datas[(i-1)/2]<datas[i])isMAX=0;
    }
    if(isMAX==1)printf("Max Heap\n");
    else{
        if(isMIN==1)printf("Min Heap\n");
        else printf("Not Heap\n");
    }
}
int main() {
    int k;
    cin>>k;
    cin>>n;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>datas[j];
        }
        judge();
        num=0;
        preorder(0);
        printf("\n");

    }
}