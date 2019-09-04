#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct edge{
    int t1,t2;
};
int main(){
    int n,m;
    vector<edge>G;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        edge t ;
        t.t1=a;
        t.t2=b;
        G.push_back(t);
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        vector<int>color;
        set<int> color_num;

        for (int j = 0; j < n; ++j) {
            int c;
            cin>>c;
            color.push_back(c);
            color_num.insert(c);
        }
        bool flag = false;
        for (int l = 0; l < G.size(); ++l) {
            if(color[G[l].t2]==color[G[l].t1]){
                flag = true;
                break;
            }
        }

        if(flag){
            printf("No\n");
        } else{
            printf("%d-coloring\n",color_num.size());
        }
    }
}