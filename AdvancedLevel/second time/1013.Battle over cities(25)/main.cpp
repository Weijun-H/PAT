#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 1000;
vector<int> G[maxn];
int vis[maxn];
void DFS(int root,int currentPoint){
    if(root == currentPoint)return;
    vis[root]= 1;
    for (int i = 0; i < G[root].size(); ++i) {
        if(vis[G[root][i]]==0)
        DFS(G[root][i],currentPoint);
    }
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < k; ++i) {
        int f;
        fill(vis,vis+maxn,0);
        cin>>f;
        int block=0;
        for (int j = 1; j <= n; ++j) {
            if(j!=f&&vis[j]==0){
                DFS(j,f);
                block++;
            }
        }
        cout<<block-1<<endl;
    }
}