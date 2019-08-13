#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
    int address, data, next;
    int order;          //无效节点为maxn
}node[maxn];
bool cmp(Node a, Node b){
    return a.order < b.order;
}
int main(){
    for (int i = 0; i < maxn; ++i) {        //初始化
        node[i].order = maxn;
    }
    int begin, n, K,address;
    scanf("%d%d%d",&begin, &n,&K);          //起始地址、结点个数、步长
    for (int i = 0; i < n; ++i) {
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int p = begin,count = 0;            //计算count
    while (p != -1){
        node[p].order = count++;
        p=node[p].next;                 //下一个节点
    }
    sort(node,node + maxn,cmp);
    n = count;
    for (int i = 0; i <n/K ; ++i) {
        for (int j = (i+1)*K-1; j > i*K; --j) {             //第i块倒着输出
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        //对于每一块的最后一个节点的next地址处理
        printf("%05d %d ",node[i*K].address,node[i*K].data);
        if (i<n /K-1){      //如果不是最后一块，就指向下一块的最后一个节点
            printf("%05d\n",node[(i+2)*K-1].address);
        }else{      //是最后一块
            if(n%K==0)printf("-1\n");   //恰好是最后一个节点，输出-1
            else{       //剩下不完整的地块按原先的顺序输出
                printf("%05d\n",node[(i+1)*K].address);
                for (int i = n/K*K; i < n; ++i) {
                    printf("%05d %d ",node[i].address,node[i].data);
                    if(i<n-1){
                        printf("%05d\n",node[i+1].address);
                    }else {printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}