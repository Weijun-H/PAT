#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000005 ;
const int INF = 0x7fffffff;
int main() {
    int n1[maxn],n2[maxn];
    int l1=0, l2=0;
    scanf("%d",&l1);
    for (int i = 0; i < l1; ++i) {
        scanf("%d",&n1[i]);
    }
    scanf("%d",&l2);
    for (int i = 0; i < l2; ++i) {
        scanf("%d",&n2[i]);             //input sequence
    }
    n1[l1]=n2[l2]=INF;
    int ans = 0;
    int cnt = 0,median;
    int i=0,j=0;
    median = (l1+l2-1)/2;
    int flag=0;
    bool odd = (l1+l2)%2?false:true;
    while (cnt<median){
        if(n1[i]<n2[j])i++;
        else j++;
        cnt++;
    }
    if (n1[i]<n2[j]){
        printf("%d",n1[i]);
    }
    else  printf("%d",n2[j]);
}