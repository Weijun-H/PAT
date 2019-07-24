#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	double a,profit = 1;
	char S[3] = { 'W','T','L' };
	char order[3];
	for (size_t i = 0; i < 3; i++)
	{
		double temp=0;
		for (size_t j = 0; j < 3; j++){
			scanf_s("%lf", &a);
			if (temp < a) {
				temp = a;
				order[i] = S[j];
			}
		}
		profit *= temp;

	}
	printf("%c %c %c %.2lf",order[0],order[1], order[2], (profit * 0.65 - 1)*2);
}