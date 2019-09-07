#include <iostream>
#include <queue>
using namespace std;
const int maxn = 40;
int n,post[maxn],in[maxn],num=0;
struct node{
    int data;
    node* lchild,*rchild;
};
node* creat(int postL,int postR,int inL,int inR){
    if(postL>postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int mid;
    for (int i = inL; i <= inR; ++i) {
        if(in[i]==root->data){
            mid=i;
            break;
        }
    }
    int num = mid - inL;
    root->lchild = creat(postL,postL+num-1,inL,mid-1);
    root->rchild = creat(postL+num,postR-1,mid+1,inR);
    return root;
}
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* p = q.front();
        q.pop();
        printf("%d",p->data);
        if(num++!=n)printf(" ");
        if(p->lchild!=NULL)q.push(p->lchild);
        if(p->rchild!=NULL)q.push(p->rchild);
    }
}
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>post[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>in[i];
    }
    node* root = creat(0,n-1,0,n-1);
    BFS(root);
}