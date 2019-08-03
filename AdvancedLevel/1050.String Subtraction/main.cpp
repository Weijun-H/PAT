#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    bool HashTable[128] ;
    fill(HashTable,HashTable+128,0);
    char s1[10000], s2[10000];
    cin.getline(s1,10000);
    cin.getline(s2,10000);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int i = 0; i < l2; ++i) {
        HashTable[s2[i]] = true;
    }
    for (int j = 0; j < l1; ++j) {
        if (HashTable[s1[j]]== false) printf("%c",s1[j]);
        else continue;
    }
    return 0;
}