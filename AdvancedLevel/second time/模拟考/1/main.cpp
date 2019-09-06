#include <iostream>
#include <string>
using namespace std;
bool cut(string x){
    long long int a=0,b=0,c=0;
    for (int i = 0; i < x.size(); ++i) {
        a = a*10+ stoi(x.substr(i,1));
    }
    for (int j = 0; j < x.size()/2 ; ++j) {
        b = b*10+ stoi(x.substr(j,1));
    }
    for (int j = x.size()/2; j < x.size() ; ++j) {
        c = c*10+ stoi(x.substr(j,1));
    }
    if(b==0||c==0)return false;
    if(a%(b*c)==0)return true;
    else return false;
}
int main(){
    int n;
    long long int a,b,c;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string num;
        cin>>num;
        if(cut(num))printf("Yes\n");
        else printf("No\n");
    }
}