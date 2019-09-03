#include <iostream>
#include <algorithm>
using namespace std;
int n;
int datas[105],temp[105],temp1[105];
bool isSame(int a[],int b[]){
    for (int i = 1; i <= n; ++i) {
        if(a[i]!=b[i])return false;
    }
    return true;
}
void downAdjust(int low, int high){
    int i = low, j = 2*i;//j表示左孩子
    while (j<=high){
        if(j+1<=high&&temp1[j+1]>temp1[j]){
            j++;
        }
        if(temp1[i]<temp1[j]){
            swap(temp1[i],temp1[j]);
            i = j;
            j = 2 * i;
        } else{
            break;
        }
    }
}
void creatHeap(){
    for (int i = n/2; i >=1 ; --i) {
        downAdjust(i,n);
    }
}

void HeapSort(){
    creatHeap();
    for (int i = n; i >1 ; --i) {
        bool flag= false;
        if(isSame(temp1,datas)){
            flag = true;
        }
        downAdjust(1,n);
        if(flag){
            for (int j = 1; j <=n ; ++j) {
                printf("%d",temp[j]);
                if(j!=n)printf(" ");
            }
            return;
        }
    }
}
int main() {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&datas[i]);
        temp[i]=datas[i];
        temp1[i]=datas[i];
    }
    for (int i = 1; i <n ; ++i) {
        int flag = false;
        if(isSame(datas,temp)){
            printf("Insertion Sort\n");
            flag = true;
        }
        sort(temp+1,temp+1+n);
        if(flag){
            for (int j = 1; j <=n ; ++j) {
                printf("%d",temp[j]);
                if(j!=n)printf(" ");
            }
            return 0;
        }
    }
    HeapSort();
    return 0;

}