#include <cstdio>
#include <set>
using namespace std;
set<int> lines[55];
int main() {
    int N,M;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &M);
        for (int j = 0; j < M; ++j) {
            int a;
            scanf("%d",&a);
            lines[i].insert(a);
        }
    }
    int cnt;
    scanf("%d",&cnt);
    for (int k = 0; k < cnt; ++k) {
        int a,b;
        float t=0.0;
        scanf("%d%d",&a,&b);
        for (set<int>::iterator i = lines[a].begin(); i != lines[a].end() ; ++i) {
            if(*(lines[b].find(*i)) == *i) t+=1;
        }
        printf("%.1f%%\n",100*t/(lines[a].size()+lines[b].size()-t));
    }
}