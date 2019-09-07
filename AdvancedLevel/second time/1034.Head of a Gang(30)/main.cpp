#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn = 2010;
int n,k,G[maxn][maxn],weigth[maxn],idx=1;
bool vis[maxn];
map<string,int>id;
map<int,string>name;
int AtoID(string a){
    if(id[a]==0){
        id[a]=idx;
        name[idx] = a;
        idx++;
    }
    return id[a];
}
void DFS(int v,int& total_weigth,int &num_member,int &head,int& maxW){
    if(weigth[v]>maxW){
        head = v;
        maxW=weigth[v];
    }
    vis[v]= true;
    num_member++;
    for (int i = 1; i < idx; ++i) {
        if(G[v][i]>0){
            total_weigth+=G[v][i];
            G[v][i]=G[i][v]=0;
            if(vis[i]== false){
                DFS(i,total_weigth,num_member,head,maxW);
            }
        }
    }
}
map<string,int> ans;
void DfsTrave(){
    fill(vis,vis+maxn,0);
    for (int i = 1; i < idx; ++i) {
        if(vis[i]== false){
            int head = -1,num_member = 0,total_weigth = 0,maxW=0;
            DFS(i,total_weigth,num_member,head,maxW);
            if(num_member>2&&total_weigth>k)
                ans[name[head]]=num_member;
        }
    }
}
int main() {
    cin>>n>>k;
    fill(weigth,weigth+maxn,0);
    fill(G[0],G[0]+maxn*maxn,0);
    for (int i = 0; i < n; ++i) {
        string a,b;
        int c;
        cin>>a>>b>>c;
        weigth[AtoID(a)]+=c;
        weigth[AtoID(b)]+=c;
        G[AtoID(a)][AtoID(b)]=c;
        G[AtoID(b)][AtoID(a)]=c;
    }
    DfsTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}