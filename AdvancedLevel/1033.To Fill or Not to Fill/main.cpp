#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station{
    double price, dis;              //价格、与起点的距离
}st[maxn];
bool cmp(station a, station b){
    return a.dis < b.dis;           //按照距离从小到大排序
}
int main() {
    int n;
    double Cmax, D, Davg;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf",&st[i].price, &st[i].dis);
    }
    st[n].price = 0;                //数组最后放置终点，价格为0
    st[n].dis = D;                    //终点距离为D
    sort(st, st+n, cmp);             //所有加油站按距离从小到大排序

    if (st[0].dis != 0){            //起点不存在加油站，无法前进
        printf("The maximum travel distance = 0.00\n");
    } else{
        int now = 0;                //当前所在加油站编号
        //总花费、当前油量及满油行驶距离
        double ans = 0, nowTank = 0, Max = Cmax * Davg;
        while (now < n){    //每次循环将选出下一次需要到达的加油站
            int k = -1;     //最低油价的加油站编号
            double priceMin = INF;      //最低油价
            for (int i = now+1; i <=n && st[i].dis-st[now].dis<=Max ; ++i) {//搜索满油状态下能到达的加油站
                if(st[i].price < priceMin){     //如果油价比当前最低油价低
                    priceMin = st[i].price;     //更新最低油价
                    k = i;
                    if (priceMin < st[now].price)break;     //如果找到第一个油价低于当前油价的加油站，直接中断循环
                }
            }

            if (k == -1) break;     //满油状态下无法找到加油站，退出循环
            double need = (st[k].dis - st[now].dis) / Davg;     //need为从now到k所需要的油量
            if (priceMin < st[now].price){                      //如果加油站k的油价低于当前油价，只买足够到达加油站k的油
                if (nowTank < st[now].price){                   //如果当前油量不足need
                    ans += (need - nowTank) * st[now].price;    //补足need
                    nowTank = 0;                                //到达加油站k后邮箱内油量为0
                } else nowTank -= need;                         //如果当前油量超过need，直接到达加油站k
            } else{     //如果加油站k的油价高于当前油价
                ans += (Cmax - nowTank) * st[now].price;        //将邮箱加满
                nowTank = Cmax - need;                          //到达加油站k后油箱内油量为Cmax-need
            }
            now = k;        //到达加油站k，进入下一层循环
        }
        if(now == n )printf("%.2f\n",ans);      //到达终点
        else printf("The maximum travel distance = %.2f\n",st[now].dis + Max);      //不能到达终点
    }
}