#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int> color;
bool cmp(map<string,int>::iterator a,map<string,int>::iterator b){
    return a->first<b->first;
}
int main() {
    int M,N;

    cin>>M>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            string a;
            cin>>a;
            if(color[a]>=1)color[a]++;
            else color[a]=1;
        }
    }
    map<string,int>::iterator ans=color.begin();
    int MAX = -1;
    for (map<string,int>::iterator k = color.begin(); k != color.end() ; ++k) {
        if(k->second>MAX){
            ans=k;
            MAX = k->second;
        }
    }
    cout<<ans->first;
}