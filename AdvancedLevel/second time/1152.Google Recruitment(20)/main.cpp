#include <iostream>
#include <string>
using namespace std;
long long n,m;
string num;
bool is_prime(long a){
    if(a==1||a==0)return false;
    for (int i = 2; i*i <= a; ++i) {
        if(a%i==0)return false;
    }
    return true;
}
int main() {
    cin>>n>>m>>num;
    int i=0;
    while (i+m-1<n){
        if(is_prime(stoi(num.substr(i,m)))){
            cout<<(num.substr(i,m));
            return 0;
        }
        i++;
    }
    cout<<"404\n";
}