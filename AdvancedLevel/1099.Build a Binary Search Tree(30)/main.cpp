#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 120;
struct node{
    int lchild, rchild;
    int data;
}Node[maxn];
int num[maxn],step=0;
int n;
void inOrder(int root){
    if(root==-1)
        return;
    inOrder(Node[root].lchild);
    Node[root].data = num[step++];
    inOrder(Node[root].rchild);
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    int i = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d",Node[now].data);
        printf("?");

        i++;
        if (i < n)printf(" ");
        if(Node[now].lchild != -1)q.push(Node[now].lchild);
        if(Node[now].rchild != -1)q.push(Node[now].rchild);
    }
}
int main() {
    scanf("%d\n",&n);
    for (int i = 0; i < n; ++i) {
        int l,r;
        scanf("%d %d\n",&l,&r);
        Node[i].lchild=l;
        Node[i].rchild=r;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&Node[i]);
    }
    sort(num, num+n);
    inOrder(0);
    BFS(0);


}