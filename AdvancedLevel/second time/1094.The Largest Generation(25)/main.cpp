#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int maxn = 105;
struct Node{
    int data;
    vector<int> child;
}node[maxn];
int layer[maxn];
void DFS(int a,int l){
    layer[l]++;
    for (int i = 0; i < node[a].child.size(); ++i) {
        DFS(node[a].child[i],l+1);
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int node1,k;
        cin>>node1>>k;
        for (int j = 0; j < k; ++j) {
            int child;
            cin>>child;
            node[node1].child.push_back(child);
        }
    }
    int root = 1;
    fill(layer,layer+maxn,0);
    DFS(root,1);
    int MAX=0,ans=0;
    for (int l = 1; l < maxn; ++l) {
        if (layer[l] > MAX){
            MAX = layer[l];
            ans = l;
        }
    }
    printf("%d %d",MAX,ans);
}