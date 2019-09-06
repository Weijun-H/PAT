#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100000;
struct Node{
    int address;
    int data;
    int next;
}node[maxn];
vector<int> nlist,klist,elist,ans;
int main() {
    int start,n,k;
    cin>>start>>n>>k;
    for (int i = 0; i < n; ++i) {
        int address;
        cin>>address;
        cin>>node[address].data>>node[address].next;
        node[address].address=address;
    }
    int p = start;
    while (p!=-1){
        if(node[p].data<0)nlist.push_back(p);
        else if(node[p].data>=0&&node[p].data<=k)klist.push_back(p);
        else elist.push_back(p);
        p=node[p].next;
    }
    int i=0,j=0,l=0;
    while (i<nlist.size()||j<klist.size()||l<elist.size()){
        if(i<nlist.size()){
            ans.push_back(node[nlist[i]].address);
            i++;
            continue;
        }
        if(j<klist.size()){
            ans.push_back(node[klist[j]].address);
            j++;
            continue;
        }
        if(l<elist.size()){
            ans.push_back(node[elist[l]].address);
            l++;
            continue;
        }
    }
    for (int m = 0; m < ans.size()-1; ++m) {
        printf("%05d %d %05d\n",ans[m],node[ans[m]].data,ans[m+1]);
    }
    printf("%05d %d -1",ans[ans.size()-1],node[ans[ans.size()-1]].data);


}