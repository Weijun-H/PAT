#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int n;
stack<int> input;
vector<int> pre,in;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int num;
void postorder(node* root){
    if(root==NULL)return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
    num++;
    if(num!=n)printf(" ");
}
node* creat_tree(int preL, int preR,int inL, int inR){
    if (preL>preR)return NULL;
    node* root = new node;
    root->data = pre[preL];
    int mid;
    for (int i = 0; i < n; ++i) {
        if(pre[preL]==in[i]){
            mid = i;
            break;
        }
    }
    int numLeft = mid-inL;
    root->lchild = creat_tree(preL+1,preL+numLeft,inL,mid-1);
    root->rchild = creat_tree(preL+numLeft+1,preR,mid+1,inR);
    return root;
}
int main() {
    cin>>n;
    for (int i = 0; i < 2*n; ++i) {
        string a;
        cin>>a;
        if(a=="Push"){
            int num;
            cin>>num;
            input.push(num);
            pre.push_back(num);
            continue;
        } else if(a=="Pop"){
            int num;
            num = input.top();
            input.pop();
            in.push_back(num);
            continue;
        }
    }
    node* root = creat_tree(0,n-1,0,n-1);
    postorder(root);
}
