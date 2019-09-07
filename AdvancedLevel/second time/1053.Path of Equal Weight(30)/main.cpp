#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
int n,m,s,weight[maxn];
bool cmp(int a,int b){
    return weight[a]>weight[b];
}
struct Node{
    int weight;
    vector<int> child;
}node[maxn];
vector<int>ans;
void DFS(int root,int w){
    ans.push_back(weight[root]);
    if(node[root].child.size()==0){
        if (w==s){
            for (int i = 0; i < ans.size(); ++i) {
                printf("%d",ans[i]);
                if(i!=ans.size()-1)printf(" ");
                else printf("\n");
            }
        } else if(w>s)return;
    }
        for (int i = 0; i < node[root].child.size(); ++i) {
            sort(node[root].child.begin(),node[root].child.end(),cmp);
            DFS(node[root].child[i],w+weight[node[root].child[i]]);
            ans.pop_back();
        }

}
int main(){
    cin>>n>>m>>s;
    int root = 0;
    for (int i = 0; i < n; ++i) {
        int w;
        cin>>w;
        weight[i]=w;
    }
    for (int j = 0; j < m; ++j) {
        int id,child_num;
        cin>>id>>child_num;
        for (int i = 0; i < child_num; ++i) {
            int a;
            cin>>a;
            node[id].child.push_back(a);
        }
    }
    DFS(root,weight[root]);
}