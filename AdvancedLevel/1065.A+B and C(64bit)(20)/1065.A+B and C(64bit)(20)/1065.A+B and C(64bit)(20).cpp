#include<cstdio>
using namespace std;
#define ll long long
int main() {
	bool times[10];
	int time;
	scanf_s("%lld", &time);
	for (size_t i = 0; i < time; i++)
	{
		ll a, b, c, res;
		scanf_s("%lld%lld%lld", &a, &b, &c);
		res = a + b;
		if (a > 0 && b > 0 && res < 0) times[i] = true;
		else if (a < 0 && b < 0 && res > 0) times[i] = false;
		else if (res > c) times[i] = true;
		else if (res < c) times[i] = false;
	}
	for (size_t i = 0; i < time; i++)
	{
		if ( times[i] ) printf("Case#%d:true\n", i + 1);
		else printf("Case#%d:false\n", i + 1);

	}
}