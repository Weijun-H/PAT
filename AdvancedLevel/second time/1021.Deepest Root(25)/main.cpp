#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
int father[maxn];
bool vis[maxn];
int findfather(int x){
    int a = x;
    while (x!=father[x]){
        x = father[x];
    }
    while (a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a,int b){
    int FaA = findfather(a);
    int FaB = findfather(b);
    if(FaA!=FaB){
        father[FaA]=FaB;
    }
}
int cakBlock(int n){
    int Root[maxn];
    int block=0;
    fill(Root,Root+maxn,0);
    for (int i = 1; i <= n; ++i) {
        Root[findfather(i)]++;
    }
    for (int i = 1; i <=n ; ++i) {
        if(Root[i]>0)block++;
    }
    return block;
}
void init(){
    for (int i = 1; i < maxn; ++i) {
        father[i]=i;
    }
}
set<int>ans;
int max_deep=0;
void dfs(int node,int deep,int root){
    if(max_deep<deep){
        ans.clear();
        ans.insert(root);
        max_deep=deep;
    }else if(max_deep==deep){
        ans.insert(root);
    }
    vis[node]= true;
    for (int i = 0; i < G[node].size(); ++i) {
        if(vis[G[node][i]]== false)dfs(G[node][i],deep+1,root);
        else continue;
    }
}
int main(){
    init();
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    int block = cakBlock(n);
    if(block>1){
        printf("Error: %d components",block);
        return 0;
    }
    for (int j = 1; j <=n ; ++j) {
        fill(vis,vis+maxn,0);
        dfs(j,1,j);
    }
    for (auto k = ans.begin(); k != ans.end(); ++k) {
        printf("%d\n",*k);
    }
}