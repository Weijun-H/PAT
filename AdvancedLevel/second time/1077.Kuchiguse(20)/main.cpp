#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
string sentences[maxn];
int main() {
    int n;
    scanf("%d\n",&n);
    int min_len=30000;
    for (int i = 0; i < n; ++i) {
        getline(cin,sentences[i]);
        if(sentences[i].size()==0){
            printf("nai");
            return 0;
        }
        min_len = (min_len>sentences[i].size())?sentences[i].size():min_len;
    }
    string res="";
    int common = 0;
    bool flag = true;
    for (int i = 0; i < min_len; ++i) {
        char temp = sentences[0][sentences[0].size()-1-i];
        for (int j = 0; j < n; ++j) {
            if(temp==' '||temp != sentences[j][sentences[j].size()-1-i]){
                flag = false;
                break;
            }

        }
        if(flag)common++;
        else break;
    }
    if (common==0)printf("nai");
    else cout<<sentences[0].substr(sentences[0].size()-common,common+1);

}