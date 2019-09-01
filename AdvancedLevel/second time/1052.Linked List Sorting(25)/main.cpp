#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000000;
struct Node{
    bool flag= false;
    int address,data,next;
}node[maxn];
bool cmp(Node a, Node b){
    if(a.flag== false||b.flag== false){
        return a.flag>b.flag;
    } else return a.data<b.data;
}
int main() {
    int n,begin;
    cin>>n>>begin;
    for (int i = 0; i < n; ++i) {
        int address,data,next;
        cin>>address>>data>>next;
        node[address].address=address;
        node[address].data=data;
        node[address].next=next;
    }
    int p = begin;
    int cnt =0;
    while (p!=-1){
        node[p].flag= true;
        p=node[p].next;
        cnt++;
    }
    sort(node,node+maxn,cmp);
    
    printf("%d %05d\n",cnt,node[0].address);
    for (int i = 0; i < cnt-1; ++i) {
        printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
    }
    printf("%05d %d -1",node[cnt-1].address,node[cnt-1].data);


}