#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000;
vector<int> G[maxn];
void DFS(int start,int end,int cnt){
    if(start==end){

    }
}
int main() {
    int n_line;
    cin>>n_line;
    for (int i = 0; i < n_line; ++i) {
        int n_station;
        cin>>n_station;
        int a,b;
        cin>>a;
        for (int j = 0; j < n_station-1; ++j) {
            cin>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    int n_guest;
    cin>>n_guest;
    for (int i = 0; i < n_guest; ++i) {
        int start,end;
        cin>>start>>end;
    }
}