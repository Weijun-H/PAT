#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    node* lchild,*rchild;
};
void insert(node* &root,int data){
    if(root == NULL){
        root = new node;
        root->data=data;
        root->lchild=root->rchild=NULL;
        return;
    }
    if(abs(data)>abs(root->data)){
        insert(root->rchild,data);
    } else insert(root->lchild,data);
}
node* Create(int data[],int n){
    node*root = NULL;
    for (int i = 0; i < n; ++i) {
        insert(root,data[i]);
    }
    return root;
}
bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->data < 0) {
        if (root->lchild != NULL && root->lchild->data < 0) return false;
        if (root->rchild != NULL && root->rchild->data < 0) return false;
    }
    return judge1(root->lchild) && judge1(root->rchild);
}
int getnum(node* root){
    if(root==NULL)return 0;
    int l = getnum(root->lchild);
    int r = getnum(root->rchild);
    return root->data>0?max(r,l)+1:max(l,r);
}
bool judge2(node *root) {
    if (root == NULL) return true;
    int l = getnum(root->lchild);
    int r = getnum(root->rchild);
    if(l != r) return false;
    return judge2(root->lchild) && judge2(root->rchild);
}
int main(){
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        int n;
        cin>>n;
        int data[35];
        for (int j = 0; j < n; ++j) {
            cin>>data[j];
        }
        node*root;
        bool flag = true;
        root = Create(data,n);
        if(data[0]<0||judge1(root) == false || judge2(root) == false){
            printf("No\n");
        }else printf("Yes\n");
    }
}