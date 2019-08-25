#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1000;
struct Guest{
    char id[20];
    int sign_in[3];
    int sign_out[3];

}guest[maxn];
bool early(Guest a, Guest b){
    if(a.sign_in[0]<b.sign_in[0])return true;
    else if(a.sign_in[0]==b.sign_in[0]){
        if (a.sign_in[1]<b.sign_in[1])return true;
        else if(a.sign_in[1]==b.sign_in[1]){
            if(a.sign_in[2]<b.sign_in[2])return true;
            else return false;
        }else return false;
    } else return false;
}
bool late(Guest a, Guest b){
    if(a.sign_out[0]>b.sign_out[0])return true;
    else if(a.sign_out[0]==b.sign_out[0]){
        if (a.sign_out[1]>b.sign_out[1])return true;
        else if(a.sign_out[1]==b.sign_out[1]){
            if(a.sign_out[2]>b.sign_out[2])return true;
            else return false;
        }else return false;
    } else return false;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",guest[i].id);
        int hour,minute,second;
        scanf("%d:%d:%d",&hour,&minute,&second);
        guest[i].sign_in[0]=hour;
        guest[i].sign_in[1]=minute;
        guest[i].sign_in[2]=second;
        scanf("%d:%d:%d",&hour,&minute,&second);
        guest[i].sign_out[0]=hour;
        guest[i].sign_out[1]=minute;
        guest[i].sign_out[2]=second;
    }
    sort(guest,guest+n,early);
    printf("%s ",guest[0].id);
    sort(guest,guest+n,late);
    printf("%s",guest[0].id);

}