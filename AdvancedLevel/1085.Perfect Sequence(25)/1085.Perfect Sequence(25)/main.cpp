#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;


int main(){
	int N, p, num[maxn];
	scanf_s("%d %d", &N, &p);
	for (size_t i = 0; i < N; i++)
	{
		scanf_s("%d", &num[i]);
	}
	sort(num, num + N);
	int ans = 1;
	for (int i = 0; i < N; i++)
	{
		int j = upper_bound(num + i + 1, num + N, (long long)num[i] * p) - num;//返回满足条件的第一个值
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
}