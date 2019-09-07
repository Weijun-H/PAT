#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int maxn = 1020,INF = 1e9;
int n,m,k,D;
int G[maxn][maxn],dis[maxn];
bool vis[maxn];
map<string,int>id;
void init(){
    for (int i = 1; i <=n ; ++i) {
        id[to_string(i)]=i;
    }
    for (int i = n+1; i <=n+m ; ++i) {
        id["G"+to_string(i-n)]=i;
    }
}
void Dijkstra(int s){
    fill(vis,vis+maxn,0);
    fill(dis,dis+maxn,INF);
    dis[s] = 0;
    for (int i = 1; i <= n+m ; ++i) {
        int u = -1,MIN = INF;
        for (int j = 1; j <=n+m ; ++j) {
            if(dis[j]<MIN&&vis[j]== false){
                MIN = dis[j];
                u = j;
            }
        }
        if(u==-1)return;
        vis[u]= true;
        for (int j = 1; j <= n+m ; ++j) {
            if(G[u][j]!=INF&&vis[j]== false){
                if(dis[j]>dis[u]+G[u][j])
                    dis[j]=dis[u]+G[u][j];
            }
        }
    }
}
int main() {
    cin>>n>>m>>k>>D;
    fill(G[0],G[0]+maxn*maxn,INF);
    init();
    for (int i = 0; i < k; ++i) {
        string a,b;
        int c;
        cin>>a>>b>>c;
        G[id[a]][id[b]]=G[id[b]][id[a]]=c;
    }

    int station=-1;
    double ans_avg,ans_MIN=0;
    for (int j = n+1; j <=n+m ; ++j) {
        Dijkstra(j);
        int MIN = INF;
        double Avg = 0;
        bool flag = true;
        for (int i = 1; i <= n ; ++i) {
            if(dis[i]>D){
                flag = false;
                break;
            }
            if(MIN>dis[i]){
                MIN=dis[i];
            }
            Avg += 1.0*dis[i]/n;
        }
        if(!flag)continue;
        if(MIN>ans_MIN){
            station = j-n;
            ans_avg = Avg;
            ans_MIN=MIN;
        }else if(MIN==ans_avg&&Avg<ans_avg){
            station = j-n;
            ans_avg = Avg;
            ans_MIN=MIN;
        }
    }
    if(station==-1){
        printf("No Solution");
        return 0;
    } else{
        printf("G%d\n%.1lf %.1lf",station,ans_MIN,ans_avg);
    }
}