#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 55;
int shuffle_order[maxn];
int cards[maxn],new_cards[maxn];
char huase[5]={'S','H','C','D','J'};
int main() {
    int time;
    scanf("%d",&time);
    for (int k = 1; k < maxn; ++k) {
        cards[k] = k;
    }
    for (int i = 1; i < maxn; ++i) {
        scanf("%d",&shuffle_order[i]);
    }
    for (int i = 0; i < time; ++i) {
        for (int j = 1; j < maxn; ++j) {
            new_cards[shuffle_order[j]] = cards[j];
        }
        for (int k = 1; k < maxn; ++k) {
            cards[k] = new_cards[k];
        }
    }
    for (int i = 1; i < maxn; ++i) {
        cards[i]--;
        printf("%c%d",huase[cards[i]/13],cards[i]%13+1);
        if (i!=maxn-1)printf(" ");
    }
}