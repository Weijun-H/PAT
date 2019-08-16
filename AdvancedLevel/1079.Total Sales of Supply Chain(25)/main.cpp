#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node{
    double data;        //货物量
    vector<int> child;  //指针域
}Node[maxn];

int n;
double p, r, ans = 0;   //ans为叶结点货物的价格之和
void DFS(int index, int depth){
    if(Node[index].child.size()==0){        //到达叶结点
        ans += Node[index].data*pow(1+r,depth);     //累加叶结点货物的价格
        return;
    }
    for (int i = 0; i < Node[index].child.size(); ++i) {    //未到达叶结点，递归访问子结点
        DFS(Node[index].child[i],depth+1);
    }
}

int main() {
    int k, child;
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        if(k==0)scanf("%lf",&Node[i].data);
        else {
            for (int j = 0; j < k; ++j) {
                scanf("%d",&child);
                Node[i].child.push_back(child);     //child为结点i的子结点
            }
        }
    }
    DFS(0,0);
    printf("%.1lf\n",p*ans);
    return 0;
}