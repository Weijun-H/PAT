#include <iostream>
using namespace std;
const int maxn = 105;
int n;
int num[maxn],temp[maxn],cpy[maxn];
void mergesort(int A[],int L1,int R1,int L2,int R2){
    int i=L1, j=L2;
    int temp[maxn],index;
    while (i<=R1&&j<=R2){
        if(A[i]<A[j])temp[index]=A[i++];
        else temp[index]=A[j++];
    }
    while (i<=R1)temp[index++]=A[i++];
    while (j<=R2)temp[index++]=A[j++];
    for (int k = 0; k < index; ++k) {
        A[L1+i] = temp[i];
    }
    bool flag = true;
    for (int j = 0; j < n; ++j) {
        if(A[i]!=temp[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        for (int j = 0; j < n; ++j) {
            printf("%d",A[j]);
            if(j!=n-1)printf(" ");
        }
    }

}
void MergeSort(int A[], int left, int right){
    while (left<right){
        int mid = (right+left)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        mergesort(A,left,mid,mid+1,right);
    }
}

int main() {
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
        cpy[i] = num[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>temp[i];
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        flag = true;
        sort(num,num+i);
        for (int j = 0; j < n; ++j) {
            if(num[i]!=temp[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("Insertion Sort\n");
            for (int j = 0; j < n; ++j) {
                printf("%d",num[j]);
                if(j!=n-1)printf(" ");
            }
            return 0;
        }
    }
    printf("Merge Sort\n");
    MergeSort(cpy,0,n);

}