#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 300005;
struct Student{
    long long  id;
    int grade;
    int order[3];//final_rank; location_number; local_rank;
}student[maxn];
bool cmp(Student a, Student b){
    if(a.grade==b.grade)return a.id<a.id;
    else return a.grade>b.grade;
}
int main() {
    int n;
    long long  idx=0;
    scanf("%d",&n);
    int now=0;
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d",&m);
        for (int j = 0; j < m; ++j) {
            scanf("%lld %d",&student[idx].id,&student[idx].grade);
            student[idx].order[1]=i+1;
            idx++;
        }
        sort(student+now,student+now+m,cmp);
        student[now].order[2]=1;
        for (int k = now+1; k < now+m; ++k) {
            if(student[k-1].grade==student[k].grade)student[k].order[2]=student[k-1].order[2];
            else student[k].order[2]=k-now+1;
        }
        now += m;
    }
    sort(student,student+idx,cmp);
    student[0].order[0]=1;
    for (int k = 1; k < idx; ++k) {
        if(student[k-1].grade==student[k].grade){
            student[k].order[0]=student[k-1].order[0];
        }
        else student[k].order[0]=k+1;
    }
    printf("%lld\n",idx);
    for (int i = 0; i < idx; ++i) {
        printf("%lld %d %d %d\n",student[i].id,student[i].order[0],student[i].order[1],student[i].order[2]);
    }
}