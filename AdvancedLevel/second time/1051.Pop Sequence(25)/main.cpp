#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
    int capacity,n,kk;
    cin>>capacity>>n>>kk;
    for (int i = 0; i < kk; ++i) {
        queue<int> test;
        bool out_size = false;
        stack<int> origin;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin>>tmp;
            test.push(tmp);
        }
        for (int k = 1; k <=n ; ++k) {
            if(origin.size()>=capacity){
                out_size = true;
                break;
            }
            origin.push(k);
            while (!origin.empty()){
                if(test.front()==origin.top()){
                    test.pop();
                    origin.pop();
                } else{
                    break;
                }

            }
        }
        if(origin.size()!=0||out_size){
            cout<<"NO\n";
        }else cout<<"YES\n";
    }
}