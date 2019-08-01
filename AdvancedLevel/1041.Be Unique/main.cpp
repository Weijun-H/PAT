#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n;
    int bet[1000010];
    int hash[10010] = {0};//只出现一次为false
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &bet[i]);
        hash[bet[i]] += 1;
    }
    bool has_print = false;
    for (int i = 0; i < n; ++i) {
        if (hash[bet[i]]==1) {
            has_print = true;
            printf("%d",bet[i]);
            break;
        }
    }
    if (!has_print) printf("None");
}
