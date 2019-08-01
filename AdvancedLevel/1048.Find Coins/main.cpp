#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, P,coins[100005];
    fill(coins,coins+100005,0);
    scanf("%d %d",&N,&P);
    bool flag = false;
    for (int i = 0; i < N ; ++i) {
        int a;
        scanf("%d",&a);
        coins[a] ++;
    }
    for (int j = 1; j < P; ++j) {
        if (coins[j]>0 && coins[P-j]>0){
            if (2*j!=P) {
                printf("%d %d",j,P-j);
                flag = true;
                break;
            }
            else {
                if (coins[j]>=2) {
                    printf("%d %d",j,P-j);
                    flag = true;

                    break;
                }
        }

            }
        }
    if(!flag) printf("No Solution");
    }
