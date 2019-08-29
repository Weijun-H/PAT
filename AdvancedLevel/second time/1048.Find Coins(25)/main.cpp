#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100005;
int main() {
    int HashTable[maxn];
    fill(HashTable,HashTable+maxn,0);
    int n,amount;
    cin>>n>>amount;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        HashTable[t]+=1;
    }
    for (int i = 1; i < amount/2+1; ++i) {
        if(HashTable[i]!=0&&HashTable[amount-i]!=0){
            if(2*i==amount){
                if(HashTable[i]>2){
                    cout<<i<<" "<<amount-i;
                    return 0;
                } else continue;
            }else{
            cout<<i<<" "<<amount-i;
            return 0;}
        }
    }
    cout<<"No Solution";
}