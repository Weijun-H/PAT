#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
double p,r,ans=0;
const int maxn = 100005;
struct Node{
    int layer;
    vector<int>child;
    int product;
}node[maxn];
void DFS(Node root,int layer){
    root.layer=layer;
    if(root.child.size()==0){
        ans+=pow(1+r,root.layer)*p*root.product;
        return;
    }else{
        for (int i = 0; i < root.child.size(); ++i) {
            DFS(node[root.child[i]],layer+1);
        }
    }
    return;
}
int main() {
    cin>>n>>p>>r;
    r = r/100;
    for (int i = 0; i < n; ++i) {
        int num_child;
        cin>>num_child;
        if(num_child==0){
            int product;
            cin>>product;
            node[i].product = product;
        } else{
            for (int j = 0; j < num_child; ++j) {
                int child;
                cin>>child;
                node[i].child.push_back(child);
            }
        }
    }
    DFS(node[0],0);
    printf("%.1lf",ans);
}