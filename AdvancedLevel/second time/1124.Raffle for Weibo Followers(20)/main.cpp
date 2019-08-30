#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> in;
const int maxn = 1005;
int main() {
    int M,N,S;
    cin>>M>>N>>S;
    string follwers[M];
    for (int i = 0; i < M; ++i) {
        cin>>follwers[i];
    }
    if(S>M)cout<<"Keep going...";
    else{
        for (int i = S-1; i < M; i+=N) {
            if(in[follwers[i]]==0){
                in[follwers[i]]=1;
                cout<<follwers[i]<<endl;
            } else if(in[follwers[i]]!=0){
                for (int j = i+1; j <i+N-1&&j<M ; ++j) {
                    if(in[follwers[j]]==0){
                        in[follwers[j]]=1;
                        cout<<follwers[j]<<endl;
                        break;
                    }
                }
            }
        }
    }
}