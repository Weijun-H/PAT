#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student{
    char id[10];
    int sum;
    int talent;
    int virtue;
    int flag;
}stu[100010];

bool cmp(Student a,Student b){
    if(a.flag != b.flag) return a.flag <b.flag;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.virtue != b.virtue) return  a.virtue > b.virtue;
    else return strcmp(a.id,b.id) < 0;
}

int main() {
    int N,L,H;
    scanf("%d%d%d",&N,&L,&H);
    int m = N;
    for (int i = 0; i < N; ++i) {
        scanf("%s%d%d",stu[i].id,&stu[i].virtue,&stu[i].talent);
        stu[i].sum = stu[i].virtue + stu[i].talent;
        if (stu[i].virtue < L||stu[i].talent<L ){
            stu[i].flag = 5;
            m--;
        }
        else if(stu[i].virtue >= H && stu[i].talent >= H) stu[i].flag = 1;
        else if(stu[i].virtue >= H && stu[i].talent < H) stu[i].flag = 2;
        else if(stu[i].virtue >= stu[i].talent ) stu[i].flag = 3;
        else stu[i].flag = 4;
    }
    sort(stu,stu+N,cmp);
    printf("%d\n",m);
    for (int i = 0;i<m;i++){
        printf("%s %d %d\n",stu[i].id,stu[i].virtue,stu[i].talent);
    }

}