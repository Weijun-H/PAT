#include <iostream>
#include <map>
using namespace std;
map<int,int>ranks;
int a[100000]={0};
bool is_prime(int a){
    if(a==1||a==0)return false;
    for (int i = 2; i*i <=a ; ++i) {
        if(a%i==0)return false;
    }
    return true;
}
int main() {
    int n;
    int m;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d",&tmp);
        ranks[tmp]=i+1;
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        int flag = false;
        int tmp;
        scanf("%d",&tmp);
        if(ranks[tmp]==0){
            printf("%04d: Are you kidding?\n",tmp);
            continue;
        }

        if(a[tmp]==0){
            a[tmp]=1;
        }else{
            printf("%04d: Checked\n",tmp);
            continue;
        }
        if(ranks[tmp]==1)printf("%04d: Mystery Award\n",tmp);
        else if(is_prime(ranks[tmp]))printf("%04d: Minion\n",tmp);
        else printf("%04d: Chocolate\n",tmp);
    }
}