#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 105;
struct Node{
    int data;
    int lchild,rchild;
}node[maxn];
int n;
int datas[maxn],num=0;
void inorder(int root){
    if(root==-1)return;
    inorder(node[root].lchild);
    node[root].data = datas[num++];
    inorder(node[root].rchild);
}
void BFS(int root){
    queue<int>q;
    q.push(root);
    while (!q.empty()){
        int p = q.front();
        q.pop();
        printf("%d",node[p].data);
        if(num!=0)printf(" ")''
        if(node[p].lchild!=-1)q.push(node[p].lchild);
        if(node[p].rchild!=-1)q.push(node[p].rchild);

    }
}
int main() {
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>node[i].lchild>>node[i].rchild;
    }
    for (int i = 0; i < n; ++i) {
        cin>>datas[i];
    }
    sort(datas,datas+n);
    inorder(0);
    BFS(0);
}