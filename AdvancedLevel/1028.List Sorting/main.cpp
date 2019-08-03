#include <cstdio>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    char name[10];
    int grade;
}stu[100005];

int n;
int col;

bool cmp(Student a, Student b){
    if(col==2){
        int s = strcmp(a.name,b.name);
        if (s==0) return a.id<b.id;
        else return s<0;
    }
    else if (col==1) return a.id<b.id;
    else {
        if (a.grade==b.grade)return a.id<b.id;
        else return a.grade<b.grade;
    }
};

int main() {
    scanf("%d %d",&n,&col);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
    }
    sort(stu,stu+n,cmp);
    for (int j = 0; j < n; ++j) {
        printf("%06d %s %d\n",stu[j].id,stu[j].name,stu[j].grade);

    }
}