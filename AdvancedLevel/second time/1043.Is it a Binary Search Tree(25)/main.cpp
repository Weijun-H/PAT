#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    node*lchild=NULL,*rchild=NULL;
    node(int d):data(d){}
};
void insert(node*& root,int data){
    if(root==NULL){
        root = new node(data);
        return;
    }
    if(root->data>data)insert(root->lchild,data);
    else insert(root->rchild,data);
}
vector<int>pre,premirror,post,post_mirror;
void preorder(node* root){
    if(root==NULL)return;
    pre.push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void preorder_mirror(node* root){
    if(root==NULL)return;
    premirror.push_back(root->data);
    preorder_mirror(root->rchild);
    preorder_mirror(root->lchild);
}
void postorder(node*root){
    if(root==NULL)return;
    postorder(root->lchild);
    postorder(root->rchild);
    post.push_back(root->data);
}
void postorder_mirror(node*root){
    if(root==NULL)return;
    postorder_mirror(root->rchild);
    postorder_mirror(root->lchild);
    post_mirror.push_back(root->data);
}
int main(){
    int n;
    cin>>n;
    node*root = NULL;
    vector<int>origin;
    for (int i = 0; i < n; ++i) {
        int data;
        cin>>data;
        insert(root,data);
        origin.push_back(data);
    }
    preorder(root);
    preorder_mirror(root);
    postorder(root);
    postorder_mirror(root);

    if(origin==pre){
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            printf("%d",post[i]);
            if(i!=post.size()-1)printf(" ");
        }
    }
    else if(origin==premirror){
        printf("YES\n");
        for (int i = 0; i < post_mirror.size(); ++i) {
            printf("%d",post_mirror[i]);
            if(i!=post_mirror.size()-1)printf(" ");
        }
    }
    else{printf("NO\n");}

}