#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2010;
struct Student{
    int id=0,C,M,E,A;
    int order[4];//A,C,M,E
}student[maxn];
char course[4]={'A','C','M','E'};
bool cmp1(Student a, Student b){
    return a.A>b.A;
}
bool cmp2(Student a, Student b){
    return a.C>b.C;
}
bool cmp3(Student a, Student b){
    return a.M>b.M;
}
bool cmp4(Student a, Student b){
    return a.E>b.E;
}
map<int,int> strToid;
int main() {
    int n, m,id;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
       scanf("%d%d%d%d",&student[i].id,&student[i].C,&student[i].M,&student[i].E);
       student[i].A = student[i].C+student[i].M+student[i].E;
       strToid[student[i].id]=i;
    }

    sort(student,student+n,cmp1);
    student[0].order[0]=1;
    for (int i = 1; i < n; ++i) {
        if(student[i].A!=student[i-1].A){
            student[i].order[0]=i+1;
        } else student[i].order[0]=student[i-1].order[0];
    }
    sort(student,student+n,cmp2);
    student[0].order[1]=1;
    for (int i = 1; i < n; ++i) {
        if(student[i].C!=student[i-1].C){
            student[i].order[1]=i+1;
        } else student[i].order[1]=student[i-1].order[1];
    }
    sort(student,student+n,cmp3);
    student[0].order[2]=1;
    for (int i = 1; i < n; ++i) {
        if(student[i].M!=student[i-1].M){
            student[i].order[2]=i+1;
        } else student[i].order[2]=student[i-1].order[2];
    }
    sort(student,student+n,cmp4);
    student[0].order[3]=1;
    for (int i = 1; i < n; ++i) {
        if(student[i].E!=student[i-1].E){
            student[i].order[3]=i+1;
        } else student[i].order[3]=student[i-1].order[3];
    }

    for (int i = 0; i < m; ++i) {
        bool flag = false;
        scanf("%d",&id);
        for (int j = 0; j < n; ++j) {
            if(id==student[j].id){
                int min = maxn+10,temp;
                for (int k = 0; k < 4; ++k) {
                    if(min>student[j].order[k]){
                        min = student[j].order[k];
                        temp = k;
                    }
                }
                printf("%d %c\n",min,course[temp]);
                flag = true;
                break;
            }
        }
        if(!flag) printf("N/A\n");
    }
}