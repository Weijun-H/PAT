#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n,sum = 0,left, right;
	scanf_s("%d", &n);
	int* distance = new int[n+1];
	distance[0] = 0;
	for (size_t i = 1; i <= n; i++)
	{
		int a;
		scanf_s("%d", &a);
		sum += a;
		distance[i] = sum;
	}

	int query;
	scanf_s("%d", &query);
	int* answer = new int[query];
	for (size_t i = 0; i < query; i++)
	{
		scanf_s("%d%d", &left, &right);
		if (left > right) swap(left, right);
		int temp = distance[right-1 ] - distance[left-1];
		answer[i]=min(temp, sum - temp);
	}
	for (size_t i = 0; i < query; i++)
	{
		printf("%d\n", answer[i]);
	}
}
