#include<cstdio>
#pragma warning(suppress : 4996)
using namespace std;

int main() {
	char pattern[5] = { 'S','H','C','D','J' };
	int order[55] = {};
	int new_order[55];

	for (size_t i = 1; i < 55; i++)
	{
		order[i] = i;
	}
	int times;
	scanf("%d", &times);
	int rules[55];
	for (size_t i = 1; i < 55; i++)
	{
		int a;
		scanf("%d", &a);
		rules[i] = a;
	}
	while (--times >= 0) {
		for (size_t i = 1; i < 55; i++)
		{
			new_order[rules[i]] = order[i];

		}
		for (size_t i = 1; i < 55; i++) {
			order[i] = new_order[i];

		}

	}
	for (size_t i = 1; i < 55; i++)
	{
		if (i != 1) {
			printf(" ");
		}
		new_order[i]--;
		printf("%c%d", pattern[new_order[i] / 13], new_order[i] % 13 + 1);

	}
}