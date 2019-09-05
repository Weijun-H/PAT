#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 505,INF = 1e10;
int G[maxn][maxn];
int n,m,start,end1;
int weight[maxn],d[maxn],w[maxn],num[maxn];
bool vis[maxn]={false};
void Dijkstra(int s){
    fill(num,num+maxn,0);
    fill(d,d+maxn,INF);;
    fill(w,w+maxn,0);
    d[s]=0;
    w[s] = weight[s];
    num[s]=1;
    for (int i = 0; i < n; ++i) {
        int u = -1,MIN = INF;
        for (int j = 0; j < n; ++j) {
            if(vis[j]== false&&d[j]<MIN){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1)return;
        vis[u]= true;
        for (int j = 0; j < n; ++j) {
            if(vis[j]== false&&G[u][j]!=INF){
                if(d[u]+G[u][j]<d[j]){
                    d[j] = d[u]+G[u][j];
                    w[j] = w[u] + weight[j];
                    num[j]=num[u];
                }else if(G[u][j]+d[u]==d[j]){
                    if(w[j]<w[u]+weight[j]){
                        w[j] = w[u]+weight[j];
                    }
                    num[j] += num[u];
                }
            }
        }
    }
}
int main() {
    cin>>n>>m>>start>>end1;
    for (int i = 0; i < n; ++i) {
        cin>>weight[i];
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    for (int i = 0; i < m; ++i) {
        int a,b,t;
        cin>>a>>b>>t;
        G[a][b]=t;
        G[b][a]=t;
    }
    Dijkstra(start);
    printf("%d %d",num[end1],w[end1]);

}