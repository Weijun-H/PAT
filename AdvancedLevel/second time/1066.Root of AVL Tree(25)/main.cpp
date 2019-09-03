#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int data;
    int height;
    Node* lchild,*rchild;
};
int getHeight(Node* root){
    if(root==NULL)return 0;
    return root->height;
}
void updateHeight(Node* root){
    root->height=max(getHeight(root->rchild),getHeight(root->lchild))+1;
}
int getBanlanceFactor(Node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(Node*& root){
    Node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(Node*& root){
    Node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void insert(Node*&root,int data){
    if (root==NULL){
        root = new Node;
        root->data=data;
        root->lchild=root->rchild=NULL;
        root->height=1;
        return;
    }
    if(data<root->data){
        insert(root->lchild,data);
        updateHeight(root);
        if(getBanlanceFactor(root)==2){
            if (getBanlanceFactor(root->lchild)==1){
                R(root);
            } else if(getBanlanceFactor(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,data);
        updateHeight(root);
        if(getBanlanceFactor(root)==-2){
            if(getBanlanceFactor(root->rchild)==-1){
                L(root);
            } else if(getBanlanceFactor(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
Node* create(int data[],int n){
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        insert(root,data[i]);
    }
    return root;
}
int main() {
    int n;
    int data[25];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>data[i];
    }
    Node* root = create(data,n);
    cout<<root->data<<endl;
}