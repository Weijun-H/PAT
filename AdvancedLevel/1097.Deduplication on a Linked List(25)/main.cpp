#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int TABLE = 1000010;
struct Node{
    int address, data, next;
    int order;      //结点在链表上的序号，无效结点记为2maxn
}node[maxn];
bool isExist[TABLE] = {false};      //绝对值是否出现
bool cmp(Node a, Node b){
    return a.order<b.order;         //按order从小到大排序
}

int main() {
    memset(isExist, false, sizeof(isExist));        //初始化isExist
    for (int i = 0; i < maxn; ++i) {
        node[i].order = 2 * maxn;
    }
    int n, begin, address;
    scanf("%d%d", &begin, &n);                      //起始地址，结点个数
    for (int i = 0; i < n; ++i) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    //未删除的有效结点个数和已删除的有效结点个数
    int countValid = 0, countRemoved = 0, p = begin;
    while (p != -1) {       //枚举链表
        if (!isExist[abs(node[p].data)]) {      //未出现过
            isExist[abs(node[p].data)] = true;
            node[p].order = countValid++;
        } else {                                //出现过
            node[p].order = maxn + countRemoved++;
        }
        p = node[p].next;           //下一个结点
    }
    sort(node, node + maxn, cmp);
    int count = countValid + countRemoved;
    for (int i = 0; i < count; ++i) {
        if (i != countValid - 1 && i != count - 1)printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        else printf("%05d %d -1\n", node[i].address, node[i].data);
    }
}