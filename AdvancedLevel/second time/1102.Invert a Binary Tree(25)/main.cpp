#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int maxn = 15;
int n;
int has_root[maxn];
struct Node{
    int lchild=-1,rchild=-1;
}node[maxn];
int num =0;
void bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int p = q.front();
        q.pop();
        printf("%d",p);
        if(num++!=n-1)printf(" ");
        if(node[p].rchild!=-1)q.push(node[p].rchild);
        if(node[p].lchild!=-1)q.push(node[p].lchild);
    }
}
void inorder(int root){
    if(root==-1)return;
    inorder(node[root].rchild);
    printf("%d",root);
    if(num++!=n-1)printf(" ");
    inorder(node[root].lchild);
}
int main() {
    fill(has_root,has_root+maxn,0);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string a,b;
        cin>>a>>b;
        if(a!="-"){
            node[i].lchild=stoi(a);
            has_root[stoi(a)]=1;
        }
        if(b!="-"){
            node[i].rchild=stoi(b);
            has_root[stoi(b)]=1;
        }
    }
    int root = 0;
    while (has_root[root]==1)root++;
    bfs(root);
    printf("\n");
    num=0;
    inorder(root);
}