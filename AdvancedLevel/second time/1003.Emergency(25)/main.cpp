#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 505,INF=1e9;
int G[maxn][maxn];
int weight[maxn],w[maxn]={0},dis[maxn],num[maxn]={0};
bool visit[maxn]={false};
int main() {
    fill(G[0],G[0]+maxn*maxn,INF);
    fill(dis,dis+maxn,INF);
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    for (int i = 0; i < n; ++i) {
        cin>>weight[i];
    }
    for (int i = 0; i < m; ++i) {
        int a,b,l;
        cin>>a>>b>>l;
        G[a][b]=l;
        G[b][a]=l;
    }
    w[start]=weight[start];
    dis[start]=0;
    num[start]=1;
    for (int i = 0; i < n; ++i) {
        int u = -1,MIN = INF;
        for (int j = 0; j < n; ++j) {
            if(dis[j]<MIN&&visit[j]== false){
                u = j;
                MIN = dis[j];
            }
        }
        if(u==-1)break;
        visit[u]= true;
        for (int j = 0; j < n; ++j) {
            if(visit[j]==false&&G[u][j]!=INF){
                if(dis[u]+G[u][j]<dis[j]){
                    dis[j]=dis[u]+G[u][j];
                    w[j]=w[u]+weight[j];
                    num[j]=num[u];
                } else if(dis[u] + G[u][j]==dis[j]){
                    num[j]+=num[u];
                    if(w[u]+weight[j]>w[j]){
                        w[j]=w[u]+weight[j];
                    }
                }
            }
        }
    }
    printf("%d %d", num[end], w[end]);
}