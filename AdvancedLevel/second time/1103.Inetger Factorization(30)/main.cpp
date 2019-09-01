#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n,k,p,maxFacsum = -1;
vector<int> factor_list,ans,temp;
void init(){
    int temp = 0;
    int t=0;
    while (t<=n){
        factor_list.push_back(t);
        temp++;
        t = pow(temp,p);
    }
}
void DFS(int sum,int facsum, int index, int nowK){
    if(sum==n&&nowK==k){
        if(facsum>maxFacsum){
            ans = temp;
            maxFacsum = facsum;
        }
        return;
    }
    if(sum > n||nowK>k)return;
    if(index-1>=0){
        temp.push_back(index);
        DFS(sum+factor_list[index],facsum+index,index,nowK+1);
        temp.pop_back();
        DFS(sum,facsum,index-1,nowK);
    }
}
int main() {
    cin>>n>>k>>p;
    init();
    DFS(0,0,factor_list.size()-1,0);
    if(maxFacsum == -1)printf("Impossible\n");
    else{
        printf("%d = %d^%d",n,ans[0],p);
        for (int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d",ans[i],p);
        }
    }
}