#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
vector<int>post,in;
node* creat_tree(int postL,int postR,int inL,int inR){
    if (postL>postR)
        return NULL;
    node* root= new node;
    root->data = post[postR];
    int mid=-1;
    for (int i = inL; i <=inR ; ++i) {
        if(root->data==in[i]){
            mid = i;
            break;
        }
    }
    int numLeft = mid-inL;
    root->lchild=creat_tree(postL,postL+numLeft-1,inL,mid-1);
    root->rchild = creat_tree(postL+numLeft,postR-1,mid+1,inR);
    return root;
}
int num=0;
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if (num!=n){printf(" ");}
        if(now->lchild!=NULL)q.push(now->lchild);
        if(now->rchild!=NULL)q.push(now->rchild);
    }
}
int main() {
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        post.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        in.push_back(t);
    }
    node* root = creat_tree(0,n-1,0,n-1);
    BFS(root);
}