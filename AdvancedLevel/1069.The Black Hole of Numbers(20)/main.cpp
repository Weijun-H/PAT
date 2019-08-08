#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
char NUM_S[10]={'0','1','2','3','4','5','6','7','8','9'};
using namespace std;

bool cmp(char a ,char b){
    return a>b;
}

int main(){
    string num;
    cin>>num;
    string ans = "1";
    num.insert(0,4-num.size(),'0');
    while (ans != "6174"&&ans!="0000"){
        string a = num;
        string b = num;
        sort(a.begin(),a.end(),cmp);//递减
        sort(b.begin(),b.end());
        ans = to_string(stoi(a) - stoi(b));
        ans.insert(0,4-ans.size(),'0');
        cout<<a<<" - "<<b<<" = "<<ans<<endl;
        num = ans;
    }
}