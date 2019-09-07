#include <iostream>
#include <vector>
using namespace std;
const int maxn = 505,INF=1e9;
int dis[maxn],cost[maxn][maxn];
int G[maxn][maxn];
int n,m,start,dest;
vector<int>pre[maxn],temppath,path;
void Dijkstra(){
    fill(dis,dis+maxn,INF);
    bool vis[maxn];
    fill(vis,vis+maxn,0);
    dis[start]=0;
    for (int i = 0; i < n; ++i) {
        int u = -1,MIN=INF;
        for (int j = 0; j < n; ++j) {
            if(dis[j]<MIN&&vis[j]== false){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1)return;
        vis[u]= true;
        for (int v = 0; v < n; ++v) {
            if(vis[v]== false&&G[u][v]!=INF){
                if(dis[v]>dis[u]+G[u][v]){
                    dis[v]=dis[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v]==dis[u]+G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int mincost = INF;
void DFS(int v){
    temppath.push_back(v);
    if(v==start){
        int tempcost=0;
        for (int i = temppath.size()-1; i >0 ; --i) {
            int id = temppath[i],nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost<mincost){
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int j = 0; j < pre[v].size(); ++j) {
        DFS(pre[v][j]);
    }
    temppath.pop_back();
}
int main() {
    fill(G[0],G[0]+maxn*maxn,INF);
    cin>>n>>m>>start>>dest;
    for (int i = 0; i < m; ++i) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        G[a][b]=G[b][a]=c;
        cost[a][b]=cost[b][a]=d;
    }
    pre[start].push_back(start);
    Dijkstra();
    DFS(dest);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[dest], mincost);
    return 0;
}