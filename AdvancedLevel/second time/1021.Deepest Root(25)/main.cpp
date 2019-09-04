#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
set<int> root;
bool vis[maxn],isRoot[maxn]={0};
int n,height,maxh = -1,father[maxn];
int FindFather(int a){
    int x = a;
    while (a!=father[a]){
        a = father[a];
    }
    while (x != father[x]){
        int y = x;
        x = father[x];
        father[y] = a;
    }
    return a;
}
void Union(int a,int b){
    int FaA = FindFather(a);
    int FaB = FindFather(b);
    if(FaA!=FaB){
        father[FaA]=FaB;
    }
}
int calBlock(int n){
    int Block = 0;
    for (int i = 1; i <= n; ++i) {
        isRoot[FindFather(i)]++;
    }
    for (int i = 1; i <=n ; ++i) {
        if(isRoot[i]>0)Block++;
    }
    return Block;
}
void init(){
    for (int i = 0; i <=maxn ; ++i) {
        father[i]=i;
    }
}
void DFS(int v,int h,int r){
    if(h>maxh){
        maxh = h;
        root.clear();
        root.insert(r);
    }else if(h==maxh){
        root.insert(r);
    }
    vis[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        if(vis[G[v][i]]== false){
            DFS(G[v][i],h+1,r);
        }
    }
}
int main() {
    cin>>n;
    init();
    for (int i = 1; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    if(calBlock(n)>1){
        printf("Error: %d components",calBlock(n));
        return 0;
    }
    int max_Now=-1;
    for (int i = 1; i <=n ; ++i) {
        fill(vis,vis+n+1,0);
        DFS(i,1,i);
    }
    for (auto i = root.begin(); i != root.end(); ++i) {
        cout<<*i<<endl;
    }
}