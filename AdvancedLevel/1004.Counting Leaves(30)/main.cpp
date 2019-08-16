#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int hashTable[maxn]={0};
int maxDepth = 0;
void DFS(int index, int depth){
    maxDepth = max(depth,maxDepth);
    if(Node[index].size()==0){
        hashTable[depth]++;
        return;}
    else{
        for (int i = 0; i < Node[index].size(); ++i) {
            DFS(Node[index][i],depth+1);
        }
    }
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < k; ++i) {
        int index,child,p;
        scanf("%d%d",&index,&p);
        for (int j = 0; j < p; ++j) {
            scanf("%d",&child);
            Node[index].push_back(child);
        }
    }
    DFS(1,1);
    for (int l = 1; l < maxDepth+1; ++l) {
        printf("%d ",hashTable[l]);
    }
}