#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N =1111;
vector<int>G[N];
bool vis[N];
int currentPoint;
void DFS(int v){
    if(v==currentPoint)return;
    vis[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        if(vis[G[v][i]]== false){
            DFS(G[v][i]);
        }
    }
}
int n,m,k;
int main() {
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int query = 0; query < k; ++query) {
        cin>>currentPoint;
        fill(vis,vis+N,0);
        int block=0;
        for (int i = 1; i <= n; ++i) {
            if(i!=currentPoint&&vis[i]== false){
                DFS(i);
                block++;
            }
        }
        cout<<block-1<<endl;
    }

}