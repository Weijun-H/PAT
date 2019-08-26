#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int maxn = 10010;
struct Student{
    string name;
    bool right= false;
    int Gmid=-1,Gfin=0,G=0,Gp=0;
}student[maxn];
map<string,int> nameToid;
bool cmp(Student a, Student b){
    if(a.G>b.G)return true;
    else if(a.G==b.G){
        return a.name<b.name;
    } else return false;
}
int main() {
    int p,m,n,index=0;
    scanf("%d%d%d",&p,&m,&n);
    for (int i = 0; i < p; ++i) {
        string name;
        int Gp;
        cin>>name>>Gp;
        if(Gp<200)continue;
        nameToid[name]=index;
        student[index].name=name;
        student[index].Gp = Gp;
        index++;
    }
    for (int i = 0; i < m; ++i) {
        string name;
        int Gmid;
        cin>>name>>Gmid;
        student[nameToid[name]].Gmid = Gmid;
    }
    for (int i = 0; i < n; ++i) {
        string name;
        int Gf;
        cin>>name>>Gf;
        student[nameToid[name]].Gfin = Gf;
        if(student[nameToid[name]].Gfin>=student[nameToid[name]].Gmid)student[nameToid[name]].G = Gf;
        else student[nameToid[name]].G = round(0.6*Gf+0.4*student[nameToid[name]].Gmid);
    }
    sort(student,student+index,cmp);
    for (int i = 0; i < p; ++i) {
        if(student[i].G>=60){
            cout<<student[i].name<<" "<<student[i].Gp<<" "<<student[i].Gmid<<" "<<student[i].Gfin<<" "<<student[i].G<<endl;
        }
    }
}