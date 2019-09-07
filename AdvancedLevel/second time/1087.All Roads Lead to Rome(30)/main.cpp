#include <iostream>
#include <map>
#include <string>
#include <vector>
const int maxn = 205,INF = 1e9;
using namespace std;
int n,k,idx=1,happiness[maxn],G[maxn][maxn],dis[maxn],num[maxn];
bool vis[maxn];
vector<int>pre[maxn],temp,path;
map<string,int>cityID;
map<int,string>cityName;
int city_to_id(string a){
    if(cityID[a]==0){
        cityID[a]=idx++;
        cityName[idx-1]=a;
    }
    return cityID[a];
}
void Dijkstra(int s){
    fill(dis,dis+maxn,INF);
    fill(num,num+maxn,0);
    fill(vis,vis+maxn,0);
    dis[s]=0;
    num[s]=1;
    for (int i = 1; i <idx ; ++i) {
        int u = -1,MIN = INF;
        for (int j = 1; j < idx; ++j) {
            if(dis[j]<MIN&&vis[j]== false){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1)return;
        vis[u]= true;
        for (int v = 1; v <idx ; ++v) {
            if(vis[v]== false&&G[u][v]!=INF){
                if(dis[v]>dis[u]+G[u][v]){
                    dis[v]=dis[u]+G[u][v];
                    num[v]=num[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v]==dis[u]+G[u][v]){
                    pre[v].push_back(u);
                    num[v]+=num[u];
                }
            }
        }
    }
}
int MaxHappy = 0;
double avg_happy=0;
void DFS(int v){
    temp.push_back(v);
    if(v == 1){
        int temphappy=0;
        double tempAvg=0;
        for (int i = 0; i < temp.size(); ++i) {
            temphappy += happiness[temp[i]];
        }
        tempAvg = (1.0*temphappy)/(1.0*temp.size()-1);
        if(temphappy>MaxHappy){
            MaxHappy = temphappy;
            path=temp;
            avg_happy = tempAvg;
        }else if(temphappy==MaxHappy&&avg_happy<tempAvg){
            MaxHappy = temphappy;
            path=temp;
            avg_happy = tempAvg;
        }
        temp.pop_back();
        return;
    }
    for (int i = 0; i <pre[v].size() ; ++i) {
        DFS(pre[v][i]);
    }
    temp.pop_back();

}
int main() {
    fill(G[0],G[0]+maxn*maxn,INF);
    string city;
    int start;
    cin>>n>>k>>city;
    start = city_to_id(city);
    happiness[1]=0;
    for (int i = 0; i < n-1; ++i) {
        string a;
        int b;
        cin>>a>>b;
        happiness[city_to_id(a)]=b;
    }
    for (int i = 0; i < k; ++i) {
        string a,b;
        int c;
        cin>>a>>b>>c;
        G[cityID[a]][cityID[b]]=c;
        G[cityID[b]][cityID[a]]=c;
    }
    Dijkstra(1);
    DFS(cityID["ROM"]);
    printf("%d %d %d %d\n",num[cityID["ROM"]],dis[cityID["ROM"]],MaxHappy,int(avg_happy));
    for (int i = path.size()-1; i >=0 ; --i) {
        printf("%s",cityName[path[i]].c_str());
        if (i!=0)printf("->");
    }
}