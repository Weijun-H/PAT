#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node{            //建立结点
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn], in[maxn], post[maxn];        //先序、中序及后序
int n;  //结点个数

//当前二叉树的后序序列区间wei【postL，postR】，中序序列区间为【inL，inR】
//create函数返回构建出的二叉树的根结点地址
node* create(int postL, int postR, int inL, int inR){
    if(postL > postR) return NULL;//后序序列长度小于0，直接返回
    node* root = new node;        //建立新结点
    root->data = post[postR];
    int k;
    for (k = inL;  k<= inR ; k++) {
        if(in[k] == post[postR])break;      //在中序序列中找到in【k】 == pre【L】的结点
    }
    int numLeft = k - inL;      //左子树的结点个数
    //返回左子树的根结点地址，赋值给root的左指针
    root->lchild = create(postL, postL + numLeft -1, inL, k-1);
    //返回右子树的根结点地址，赋值给root的右指针
    root->rchild = create(postL + numLeft, postR-1, k+1, inR);
    return root;//返回根结点地址
}
int num = 0;//已输出的结点个数

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if(num<n)printf(" ");
        if(now->lchild != NULL)q.push(now->lchild);
        if(now->rchild != NULL)q.push(now->rchild);
    }

}

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&post[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&in[i]);
    }
    node* root = create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}