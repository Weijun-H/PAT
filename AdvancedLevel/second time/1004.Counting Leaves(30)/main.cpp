#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int maxn = 100;
int layer[maxn],MAX=-1;
struct Node{
    int id;
    vector<int> child;
}node[maxn];
void BFS(int root,int l) {
    queue<int>q;
    q.push(root);
    if(l>MAX)MAX=l;
    while (!q.empty()){
        int p = q.front();
        q.pop();
        if (node[p].child.size()==0){
            layer[l]++;
        }
        for (int i = 0; i < node[p].child.size(); ++i) {
            BFS(node[p].child[i],l+1);
        }
    }
}
int main() {
    int n,m,has_child[maxn];
    fill(has_child,has_child+maxn,0);
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int id,nchild;
        cin>>id>>nchild;
        for (int j = 0; j < nchild; ++j) {
            int id_child;
            cin>>id_child;
            node[id].child.push_back(id_child);
            has_child[id_child] = 1;
        }
    }
    int root = 1;
    while (has_child[root]==1)root++;
    BFS(root,0);
    for (int i = 0; i <= MAX; ++i) {
        printf("%d",layer[i]);
        if(i!=MAX)printf(" ");
    }
}