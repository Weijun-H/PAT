#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse{
    int weight;
    int R;
}mouse[maxn];
int main() {
    int np,ng,order;
    scanf("%d%d",&np,&ng);
    for (int i = 0; i < np; ++i) {
        scanf("%d",&mouse[i].weight);
    }
    queue<int> q;
    for (int i = 0; i < np; ++i) {      //按顺序老鼠入队
        scanf("%d",&order);
        q.push(order);
    }
    int temp = np, group;               //temp为当前比赛的总老鼠数，group为组数
    while (q.size()!=1){
        if(temp % ng == 0)group = temp / ng;    //刚好分
        else group = temp / ng +1;              //不能刚好分组，加一组
        for (int i = 0; i < group; ++i) {
            int k = q.front();                  //存放该组质量最大的老鼠编号
            for (int j = 0; j < ng; ++j) {
                if (i*ng +j>= temp) break;      //最后一组老鼠数不足NG时起作业，退出循环
                int front = q.front();
                if (mouse[front].weight>mouse[k].weight){
                    k = front;
                }
                mouse[front].R = group + 1;     //淘汰老鼠，更新老鼠排名
                q.pop();
            }
            q.push(k);      //把胜利老鼠重新加入晋级
        }
        temp = group;       //下一轮总老鼠数为group
    }
    mouse[q.front()].R = 1;
    for (int i = 0; i < np; ++i) {
        printf("%d",mouse[i].R);
        if(i<np-1)printf(" ");
    }
    return 0;
}