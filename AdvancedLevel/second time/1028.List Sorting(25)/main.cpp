#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100010;
int n,type;
struct Student{
    int id;
    char name[10] ;
    int grade;
}student[maxn];
bool cmp(Student a,Student b){
    if(type==1)return a.id<b.id;
    else{
        if(type==2){
            if (strcmp(a.name,b.name)==0)return a.id<b.id;
            else return strcmp(a.name,b.name)<0;
        }
        else{
            if (a.grade==b.grade)return a.id<b.id;
            else return a.grade<b.grade;
        }
    }
}
int main() {
    scanf("%d%d",&n,&type);
    for (int i = 0; i < n; ++i) {
        scanf("%d%s%d",&student[i].id,student[i].name,&student[i].grade);
    }
    sort(student,student+n,cmp);
    for (int i = 0; i < n; ++i) {
        printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
    }
}