#include <vector>
#include <iostream>
#include <set>
#include <string>
using namespace std;
const int maxn = 10000;
vector<int> G[maxn];
int main(){
    int n,m;
    set<int> num;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        num.insert(a);
        num.insert(b);
    }
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int ans = 0;
        int HashTable[maxn];
        fill(HashTable,HashTable+maxn,0);
        int n_node;
        cin>>n_node;
        bool flag = false;
        vector<int> s;
        for (int j = 0; j < n_node ; ++j) {
            int node;
            cin>>node;
            HashTable[node]=1;
            for (int k = 0; k < G[node].size(); ++k) {
                if(HashTable[G[node][k]]==0)HashTable[G[node][k]]=1;
            }
        }
        for (int j = 0; j < n; ++j) {
            if(HashTable[j]==1)
                ans++;
        }
        if(ans==num.size())printf("Yes\n");
        else printf("No\n");
    }
}