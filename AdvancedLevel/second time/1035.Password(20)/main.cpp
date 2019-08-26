#include <iostream>
#include <string>
using namespace std;
const int maxn = 1010;
int main() {
    string name[maxn], password[maxn];
    bool flag[maxn] = {false};
    fill(flag,flag+maxn,0);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>name[i]>>password[i];
    }
    int cnt =0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < password[i].size(); ++j) {
            if(password[i][j]=='1'){
                password[i][j]='@';
                flag[i] = true;
            }
            if(password[i][j]=='0'){
                password[i][j]='%';
                flag[i] = true;
            }
            if(password[i][j]=='O'){
                password[i][j]='o';
                flag[i] = true;
            }
            if(password[i][j]=='l'){
                password[i][j]='L';
                flag[i] = true;
            }

        }
        if(flag[i])cnt++;
    }
    if(cnt==0){
        if(n==1){
            printf("There is 1 account and no account is modified");
        }else{
            printf("There are %d accounts and no account is modified",n);
        }
    }else{
        printf("%d\n",cnt);
        for (int i = 0; i < n; ++i) {
            if(flag[i]){
                cout<<name[i]<<" "<<password[i];
                if(--cnt!=0)printf("\n");
            }
        }
    }
}