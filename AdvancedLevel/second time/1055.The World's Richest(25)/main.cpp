#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Man{
    char name[15];
    int age;
    int money;
}man[maxn];
bool cmp(Man a,Man b){
    if(a.money==b.money){
        if(a.age==b.age){
            return (strcmp(a.name,b.name)<0);
        } else return a.age<b.age;
    } else return a.money>b.money;
}
int main() {
    int num,query;
    scanf("%d%d",&num,&query);
    for (int i = 0; i < num; ++i) {
        scanf("%s%d%d",man[i].name,&man[i].age,&man[i].money);
    }
    sort(man,man+num,cmp);
    for (int i = 0; i < query; ++i) {
        printf("Case #%d:\n",i+1);
        bool flag = true;
        int cnt,Max,Min;
        scanf("%d%d%d",&cnt,&Min,&Max);
        for (int j = 0; j < num; ++j) {
            if(man[j].age<=Max&&Min<=man[j].age){
                printf("%s %d %d\n",man[j].name,man[j].age,man[j].money);
                flag = false;
                if(--cnt==0)break;
            }
        }
        if(flag)printf("None\n");
    }
}