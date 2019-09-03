#include <iostream>
using namespace std;
const int maxn = 10005;
int father[10005]={-1},course[10005]={0},isRoot[maxn]={0};
bool cmp(int a, int b){
    return a>b;
}
void init(){
    for (int i = 1; i <= maxn; ++i) {
        father[i]=i;
    }
};
int findFather(int i){
    int t = i;
    while (i!=father[i]){
        i=father[i];
    }
    while (t != father[t]){
        int z = t;
        t = father[t];
        father[z]=i;
    }
    return i;
}
void Unoin(int a,int b){
    int FaA = findFather(a);
    int FaB = findFather(b);
    if(FaA!=FaB){
        father[FaA]=FaB;
    }
}
int main() {
    int n;
    cin>>n;
    init();
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d:",&num);
        for (int j = 0; j < num; ++j) {
            int h;
            cin>>h;
            if(course[h]==0){
                course[h]=i;
            }
            Unoin(i,findFather(course[h]));
        }
    }
    for (int i = 1; i <= n ; ++i) {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n ; ++i) {
        if(isRoot[i]!=0)ans++;
    }
    printf("%d\n",ans);
    sort(isRoot+1,isRoot+1+n,cmp);
    for (int i = 0; i < ans; ++i) {
        printf("%d",isRoot[i+1]);
        if (i!=ans-1)printf(" ");
    }
}