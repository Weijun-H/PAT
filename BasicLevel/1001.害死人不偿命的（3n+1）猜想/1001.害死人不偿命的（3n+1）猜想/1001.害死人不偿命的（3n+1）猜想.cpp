#include<cstdio>
using namespace std;

int main() {
	int n,step=0;
	scanf_s("%d", &n);
	while (n != 1) {
		if (n % 2==0){
			n /= 2;
		}
		else {
			n = (3*n + 1) / 2;
		}
		step++;
	}
	printf("%d", step);
}