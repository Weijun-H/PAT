#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int in[maxn],n;
vector<int> temp;
void DFS(int root){
    if(root*2>n&&root*2+1){
        if(root<=n){
            for (int i = 0; i < temp.size(); ++i) {
                printf("%d",in[temp[i]]);
                if(i!=temp.size()-1)printf(" ");
            }
            printf("\n");
        }
    } else{
        temp.push_back(root*2+1);
        DFS(root*2+1);
        temp.pop_back();
        temp.push_back(root*2);
        DFS(root*2);
        temp.pop_back();
    }
}
int main() {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>in[i];
    }
    temp.push_back(1);
    DFS(1);
    int isMin=1,isMax=1;
    for (int i = 2; i <= n; ++i) {
        if(in[i/2]>in[i])isMin=0;
        if(in[i/2]<in[i])isMax=0;
    }
    if(isMax==1&&isMin==0)printf("Max Heap");
    else if(isMin==1&&isMax==0)printf("Min Heap");
    else printf("Not Heap");
}