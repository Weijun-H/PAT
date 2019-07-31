#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int hashTable[80] = {0},miss=0;
int change(char c){
    if (c >= '0' && c<= '9')return c-'0';
    if (c >= 'a' && c<= 'z')return c-'a'+10;
    if (c >= 'A' && c<= 'Z')return c-'A'+36;

}
int main() {
    char whole[MAXN];
    char target[MAXN];
    cin.getline(whole,1010);
    cin.getline(target,1010);
    int l1 = strlen(whole);
    int l2 = strlen(target);
    for (int i = 0; i < l1; ++i) {
        int id = change(whole[i]);
        hashTable[id]++;
    }
    for (int j = 0; j <l2 ; ++j) {
        int id = change(target[j]);
        hashTable[id]--;
        if (hashTable[id] < 0)miss++;
    }
    if(miss > 0)printf("No %d\n",miss);
    else printf("Yes %d\n",l1-l2);
    return 0;

}