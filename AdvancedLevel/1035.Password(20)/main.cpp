#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n,num=0 ;
    string teams[1200];
    string password[1200];
    cin<<n;
    bool judge[1200];
    fill(judge,judge+1200, false);
    for (int i = 0; i < n; ++i) {
        cin>>(teams[i]);
        cin>>(password[i]);
    }
    for (int i =0; i < n; ++i){
        for (int j = 0; j < password[i].length(); ++j) {
            if (password[i][j] == '0') {
                password[i][j] = '%';
                judge[i] = true;
            }
            else if (password[i][j] == '1') {
                password[i][j] = '@';
                judge[i] = true;
            }
            else if (password[i][j] == 'l') {
                password[i][j] = 'L';
                judge[i] = true;
            }
            else if (password[i][j] == 'O'){
                password[i][j] = 'o';
                judge[i] = true;
            }}
        if (judge[i]) num++;
        }
    if (num==0 && n==1) cout<<"There is "<<n<<" account and no account is modified";
    else if(num==0 && n>1)cout<<"There are "<<n<<" accounts and no account is modified";
    else{
        cout<<num<<'\n';
        for (int i =0; i < n; ++i){
            if(judge[i]){
                cout<<teams[i]<<' '<<password[i];
                if (i<n-1)printf("\n");
            }
        }
    }
    return 0;

}