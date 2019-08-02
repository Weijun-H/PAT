#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main() {
    int n, ans = 0;
    scanf("%d",&n);
    int left = n-1, num;        //left为除零外不在本位上的数
    for (int i = 0; i < n; ++i) {
        scanf("%d",&num);
        pos[num] = i;
        if (num == i && num != 0){      //如果除0以外有在本位上的数
            left--;
        }
    }
    int k =1;
    while (left > 0){       //还有数不再本位上
        if (pos[0] == 0){   //0在本位上，寻找不再本位的数字与零交换
            while (k < n){
                if (pos[k] != k){
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while (pos[0] != 0){        //只要0不在本位，就将0所在位置的树的当前所处位置与0的位置交换
            swap(pos[0], pos[pos[0]]);//交换
            ans++;
            left--;
        }

    }
    printf("\n%d",ans);
}

// 3 0 2 1 4
// 1 0 2 3 4
// 0 1