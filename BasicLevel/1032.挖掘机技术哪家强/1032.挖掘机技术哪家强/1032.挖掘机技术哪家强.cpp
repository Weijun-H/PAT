#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int num_people;
	scanf_s("%d", &num_people);
	int* p = new int[num_people];
	fill(p, p + num_people, 0);
	for (size_t i = 0; i < num_people; i++)
	{
		int a, b;
		scanf_s("%d%d", &a, &b);
		p[a] += b;
	}
	int max = p[0], id = 0;
	for (size_t i = 0; i < num_people; i++)
	{
		if (max<p[i])
		{
			max = p[i];
			id = i;
		}
	}
	printf("%d %d", id, max);
}