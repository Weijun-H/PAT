#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {//转换为十进制数
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto it = n.rbegin(); it != n.rend(); it++) {//string n左地址开始
		temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}

long long find_radix(string n, long long num) {//寻找合适的radix
	char it = *max_element(n.begin(), n.end());//
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;//最低进制
	long long high = max(num, low);
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long t = convert(n, mid);
		if (t < 0 || t > num) high = mid - 1;//溢出选择进制太大
		else if (t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	string n1, n2;
	long long tag = 0, radix = 0, result_radix;
	cin >> n1 >> n2 >> tag >> radix;
	result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
	if (result_radix != -1) {
		printf("%lld", result_radix);
	}
	else {
		printf("Impossible");
	}
	return 0;
}