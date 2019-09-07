#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 505,INF = 1e9;
int cmax,n,sp,m,c[maxn];
int G[maxn][maxn],dis[maxn],vis[maxn];
bool visit[maxn];
vector<int>pre[510];
int minNeed = INF, minBack = INF;
vector<int>temppath,path;
void DFS(int v){
    temppath.push_back(v);
    if(v==0){
        int need = 0,back = 0;
        for (int i = temppath.size()-1; i >=0 ; --i) {
            int id = temppath[i];
            if(c[id]>0){
                back += c[id];
            } else{
                if(back>(0-c[id])){
                    back += c[id];
                } else{
                    need += ((0-c[id])-back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(dis,dis+maxn,0);
    fill(visit,visit+maxn,0);
    fill(G[0],G[0]+maxn+maxn,INF);
    cin>>cmax>>n>>sp>>m;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin>>c[i];
        c[i] = c[i]-cmax/2;
    }
    for (int i = 0; i < m; ++i) {
        int a,b,t;
        cin>>a>>b>>t;
        G[a][b]=G[b][a]=t;
    }

    dis[0]=0;
    for (int i = 0; i <= n; ++i) {
        int u = -1,MIN = INF;
        for (int j = 1; j <=n ; ++j) {
            if(vis[j]==false&&dis[j]<MIN){
                u = j;
                MIN = dis[j];
            }
        }
        if(u==-1){
            break;
        }
        visit[u] = true;
        for (int v = 0; v <= n ; ++v) {
            if(visit[v] == false && G[u][v]!=INF){
                if (dis[v]>dis[u]+G[u][v]){
                    dis[v] = dis[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v]==dis[u]+G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    DFS(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}