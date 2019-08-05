#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 0x2fffffff;
int a[maxn],leftMax[maxn], rightMin[maxn];
int ans[maxn],num=0;

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    leftMax[0] = 0;//a[0] has nothing in left hand
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i-1],a[i-1]);
    }
    rightMin[n-1] = INF;//a[n-1] has nothing in right hand
    for (int i = n-2; i >=0 ; --i) {
        rightMin[i] = min(rightMin[i+1],a[i+1]);
    }

    for (int i = 0; i < n; ++i) {
        if(leftMax[i] < a[i]&&a[i]<rightMin[i]){
            ans[num++] = a[i];
        }
    }
    printf("%d\n",num);
    for (int i = 0; i < num; ++i) {
        printf("%d",ans[i]);
        if(i<num-1)printf(" ");
    }
}