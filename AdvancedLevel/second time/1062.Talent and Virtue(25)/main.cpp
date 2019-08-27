#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Man{
    int talent,virtue;
    int id;
    int total;
    int flag;//1 is sage;2 is nobleman;3 is small man
}man[maxn];
int n, l, h;

bool cmp(Man a, Man b){
    if(a.flag<b.flag)return true;
    else if(a.flag == b.flag){
        if(a.total == b.total){
            if(a.virtue == b.virtue)return a.id<b.id;
            else return a.virtue>b.virtue;
        }
        else return a.total>b.total;
    } else return false;
}

int main() {
    scanf("%d%d%d\n",&n,&l,&h);
    int idx =0;
    for (int i = 0; i < n; ++i) {
        int id, virtue, talent;
        scanf("%d%d%d",&id,&virtue,&talent);
        if(virtue>=l&&talent>=l){
            man[idx].id = id;
            man[idx].talent = talent;
            man[idx].virtue = virtue;
            man[idx].total = talent+virtue;
            if(talent>=h&&virtue>=h)man[idx].flag=1;
            else if(talent<h&&virtue>=h)man[idx].flag=2;
            else if(virtue>=talent)man[idx].flag = 3;
            else man[idx].flag = 4;
            idx++;
        }
    }
    printf("%d\n",idx);
    sort(man,man+idx,cmp);
    for (int i = 0; i < idx; ++i) {
        printf("%d %d %d\n",man[i].id,man[i].virtue,man[i].talent);
    }
}