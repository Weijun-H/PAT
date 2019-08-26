#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main() {
    string n;
    cin>>n;
    int sum=0;
    for (int i = 0; i < n.size(); ++i) {
        sum += stoi(n.substr(i,1));
    }
    n = to_string(sum);
    for (int i = 0; i < n.size(); ++i) {
        cout<<num[n[i]-'0'];
        if(i!=n.size()-1)cout<<' ';
    }
}