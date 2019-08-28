#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 10010;
struct Student{
    int id;
    int grade[5]={-1,-1,-1,-1,-1};
    int total=0;
    int perfect = 0;
    int rank;
}student[maxn];
bool cmp(Student a, Student b){
    if(a.total == b.total){
        if(a.perfect==b.perfect)return a.id<b.id;
        else return a.perfect>b.perfect;
    } else return a.total>b.total;
}
int p_grade[5];
map<int,int> Toindex;
int main() {
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for (int i = 0; i < k; ++i) {
        scanf("%d",&p_grade[i]);
    }
    int idx=1;
    for (int i = 0; i < m; ++i) {
        int id,p,grade;
        scanf("%d%d%d",&id,&p,&grade);
        if(Toindex[id]==0){Toindex[id]=idx;idx++;}
        int index = Toindex[id];
        student[index].id=id;
        if(grade>0){
            if(grade>student[index].grade[p-1])student[index].grade[p-1]=grade;
        } else student[index].grade[p-1]=0;
        if(p_grade[p-1]==grade)student[index].perfect++;
    }
    idx--;
    int res_num=idx;
    for (int i = 0; i < idx; ++i) {
        for (int j = 0; j < k; ++j) {
            if(student[i].grade[j]>0)student[i].total += student[i].grade[j];
        }
        if (student[i].total<=0)res_num--;
    }
    sort(student,student+idx,cmp);
    student[0].rank=1;
    for (int i = 1; i <idx ; ++i) {
        if(student[i].total==student[i-1].total)student[i].rank=student[i-1].rank;
        else student[i].rank=i+1;
    }
    for (int i = 0; i < res_num; ++i) {
        printf("%d %05d %d",student[i].rank,student[i].id,student[i].total);
        for (int j = 0; j < k; ++j) {
            if(student[i].grade[j]>=0)printf(" %d",student[i].grade[j]);
            else printf(" -");
        }
        printf("\n");
    }
}