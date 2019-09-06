#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct School{
    string name;
    int order,total;
    double scoreA,scoreB,scoreT;
    int num=0;
};
bool cmp(School a,School b){
    if(a.total==b.total){
        if(a.num==b.num){
            return a.name<b.name;
        }
        else return a.num<b.num;
    }
    else return a.total>b.total;
}
map<string,int>id_index;
using namespace std;
int main() {
    int n,index=1;
    cin>>n;
    vector<School>ans;
    for (int i = 0; i < n; ++i) {
        string id,school;
        double grade;
        cin>>id>>grade>>school;
        for (int j = 0; j < school.size(); ++j) {
            school[j] = tolower(school[j]);
        }
        if(id_index[school]==0){
            School a;
            a.name=school;
            ans.push_back(a);
            id_index[school]=index++;
        }
        int schoolID = id_index[school]-1;
        if(id[0]=='A'){ans[schoolID].scoreA+=grade;ans[schoolID].num++;}
        else if(id[0]=='B'){ans[schoolID].scoreB+=grade;ans[schoolID].num++;}
        else if(id[0]=='T'){ans[schoolID].scoreT+=grade;ans[schoolID].num++;}
    }
    for (int i = 0; i < ans.size(); ++i) {
        ans[i].total=ans[i].scoreB/1.5+ans[i].scoreA+ans[i].scoreT*1.5;
    }
    sort(ans.begin(),ans.end(),cmp);
    ans[0].order=1;
    for (int i = 1; i < ans.size(); ++i) {
        if(ans[i].total==ans[i-1].total)ans[i].order=ans[i-1].order;
        else ans[i].order = i+1;
    }
    printf("%d\n",ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %s %d %d\n",ans[i].order,ans[i].name.c_str(),ans[i].total,ans[i].num);
    }
}