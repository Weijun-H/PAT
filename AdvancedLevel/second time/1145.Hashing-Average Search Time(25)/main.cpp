#include <iostream>
#include <vector>
#include <map>
using namespace std;
int M_size,N,M;
map<int,int>Hash;
bool is_prime(int a){
    if(a==1||a==0)return false;
    for (int i = 2; i*i <= a; ++i) {
        if(a%i==0)return false;
    }
    return true;
}
void collosion(int key){
    int temp=0;
    for (int i = 1; i < M_size; ++i) {
        temp += i*i + key
        if()
    }
}
int main() {
    cin>>M_size>>N>>M;
    while (!is_prime(M_size)){
        M_size++;
    }
    vector<int> input,key;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        input.push_back(a);
    }
    for (int i = 0; i < M; ++i) {
        int a;
        cin>>a;
        key.push_back(a);
    }

}