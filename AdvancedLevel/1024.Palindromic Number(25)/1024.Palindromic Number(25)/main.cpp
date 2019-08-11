#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <cstring>
#include <string>

using namespace std;
struct bign
{
	int d[300];
	int len;
	bign() {
		fill(d, d + 300, 0);
		len = 0;
	}
}b1, b2, temp;

bool is_Pali(bign a) {
	for (size_t i = 0; i <= a.len / 2; i++)
	{
		if (a.d[i] != a.d[a.len - i - 1]) return false;
	}
	return true;
}

bign add(bign a) {
	bign t;
	int wei = 0;
	for (size_t i = 0; i < a.len; i++)
	{
		t.d[t.len++] = a.d[i] + a.d[a.len - i - 1] + wei;
		wei = t.d[i] / 10;
		t.d[i] %= 10;
	}
	if (wei != 0)t.d[t.len++] = wei;
	return t;
}

int main() {
	char num[15];
	int K;
	scanf("%s ", num);
	scanf("%d", &K);

	int n = strlen(num);
	for (size_t i = 0; i < n; i++)
	{
		b1.d[i] = num[i] - '0'; //d[]={6,7}
		b1.len++;
	}
	bool flag = is_Pali(b1);
	int cnt = 0;
	while (cnt < K && !flag)
	{
		temp = add(b1);
		flag = is_Pali(temp);
		cnt++;
		b1 = temp;
	}

	for (size_t i = 0; i < temp.len; i++)
	{
		printf("%d", temp.d[temp.len - 1 - i]);
	}
	printf("\n%d", cnt);
}

/*#include <iostream>
#include <algorithm>
using namespace std;
string s;
void add(string t) {
	int len = s.length(), carry = 0;
	for (int i = 0; i < len; i++) {
		s[i] = s[i] + t[i] + carry - '0';
		carry = 0;
		if (s[i] > '9') {
			s[i] = s[i] - 10;
			carry = 1;
		}
	}
	if (carry) s += '1';
	reverse(s.begin(), s.end());
}
int main() {
	int cnt, i;
	cin >> s >> cnt;
	for (i = 0; i <= cnt; i++) {
		string t = s;
		reverse(t.begin(), t.end());
		if (s == t || i == cnt) break;
		add(t);
	}
	cout << s << endl << i;
	return 0;
}*/