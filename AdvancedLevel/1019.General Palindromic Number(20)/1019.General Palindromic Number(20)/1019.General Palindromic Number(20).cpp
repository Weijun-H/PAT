#include<cstdio>
using namespace std;

int main() {
	int N, base;
	scanf_s("%d%d", &N, &base);
	int New_N[100];
	bool palin = true;
	int i = 0;
	while (N!=0){	
		New_N[i++] = N % base;
		N /= base;
	}
	i--;
	for (size_t j = 0; j < (i+1)/2+1 ; j++)
	{
		if (New_N[j] != New_N[i - j]) palin = false;
	}
	if (palin) printf("Yes\n");
	else
	{
		printf("No\n");
	}
	for (int j = 0; j < i + 1; j++) {
		printf("%d", New_N[i - j]);
		if (j != i)printf(" ");
	}
	return 0;
}