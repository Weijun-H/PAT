#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string num;
    cin>>n;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        flag = true;
        cin>>num;
        int j = num.size()/2;
            if(stoi(num.substr(0,j))*stoi(num.substr(j))==0)continue;
            if(stoi(num)%(stoi(num.substr(0,j))*stoi(num.substr(j)))==0){
                cout<<"Yes"<<endl;
                flag= false;
        }
        if(flag)cout<<"No\n";
    }
}