#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int father[N];
int isRoot[N] = {0};        //记录每个结点是否作为某个集合的根结点
int course[N] = {0};
int findFather(int x){      //查找x所在集合的根结点
    int a = x;
    while (x != father[x]){
        x = father[x];
    }
    while (a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b){       //合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}
void init(int n){
    for (int i = 1; i <= n ; ++i) {
        father[i] = i;
        isRoot[i] = false;
    }
}
bool cmp(int a, int b){
    return a>b;
}
int main() {
    int n, k, h;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d:",&k);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&h);
            if(course[h] == 0)course[h] = i;
            Union(i,findFather(course[h]));
        }
    }
    for (int i = 1; i <= n ; ++i) {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n ; ++i) {
        if(isRoot[i] != 0)ans++;
    }

    printf("%d\n",ans);
    sort(isRoot + 1,isRoot +1+n,cmp);
    for (int i = 1; i <= ans ; ++i) {
        printf("%d",isRoot[i]);
        if (i< ans)printf(" ");
    }
}