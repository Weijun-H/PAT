#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, min_len = 260, ans = 0;
    string speaks[110];
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        getline(cin, speaks[i]);
        reverse(speaks[i].begin(), speaks[i].end());
        if (speaks[i].length() < min_len) min_len = speaks[i].length();
    }

    for (int j = 0; j < min_len; ++j) {
        char c = speaks[0][j];
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (c != speaks[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag)ans++;

    }
    if (ans > 0) {
        for (int k = ans-1; k >= 0; --k) {
            cout << speaks[0][k];
        }

    }
    else cout<<"nai";
}