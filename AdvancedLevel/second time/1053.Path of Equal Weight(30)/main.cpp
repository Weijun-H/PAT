#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n,m,w;
struct Node{
    int weight;
    vector<int> child;
}node[maxn];
bool cmp(int a,int b){
    return node[a].weight>node[b].weight;
}
vector<int>ans,res;
void preOrder(Node root,int total_weight){
    if(total_weight>w)return;
    else if(total_weight==w){
        if(root.child.size()==0){
            for (int i = 0; i < ans.size(); ++i) {
                printf("%d",ans[i]);
                printf(" ");
            }
            printf("%d\n",root.weight);
        } else return;
    }else {
        ans.push_back(root.weight);
        for (int i = 0; i < root.child.size(); ++i) {
            sort(root.child.begin(),root.child.end(),cmp);
            preOrder(node[root.child[i]],total_weight+node[root.child[i]].weight);
        }
        ans.pop_back();
    }
}
int main() {
    cin>>n>>m>>w;
    for (int i = 0; i < n ; ++i) {
        int weight;
        cin>>weight;
        node[i].weight=weight;
    }
    for (int i = 0; i < m; ++i) {
        int index;
        cin>>index;
        int num;
        cin>>num;
        for (int j = 0; j < num; ++j) {
            int child;
            cin>>child;
            node[index].child.push_back(child);
        }
    }

    preOrder(node[0],node[0].weight);
}