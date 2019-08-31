#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map<int,vector<int>> incompatible;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        incompatible[a].push_back(b);
        incompatible[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int HashTable[100000]={0};
        vector<int> bag;
        int k;
        scanf("%d",&k);
        bool flag = false;
        for (int j = 0; j < k; ++j) {
            int t;
            scanf("%d",&t);
            bag.push_back(t);
            HashTable[t]=1;
        }
        for (int j = 0; j < bag.size(); ++j) {
            for (int l = 0; l < incompatible[bag[j]].size(); ++l) {
                if(HashTable[incompatible[bag[j]][l]]==1){
                    flag = true;
                }
            }
        }
        if(flag)printf("N0\n");
        else printf("Yes\n");
    }
}