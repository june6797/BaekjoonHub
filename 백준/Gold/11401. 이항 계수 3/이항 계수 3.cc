#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int mul(int b, int m) {
	if (m == 1)
	{
		return b;
	}
	if (m % 2 == 1)
	{
		return (b * mul(b, m - 1)) % 1000000007;
	}
	else
	{
		long long int temp = mul(b, m / 2);
		return (temp * temp) % 1000000007;
	}
}
long long int cal(int n, int k) {
	if (k == 0 || k == n)
	{
		return 1;
	}
	else if (k == 1 || k == n - 1)
	{
		return n;
	}
	long long int ans = 1, a = 1, b = 1;
	for (int i = n - k + 1; i <= n; i++)
	{
		a = (a * i) % 1000000007;
	}
	for (int i = 1; i <= k; i++)
	{
		b = (b * i) % 1000000007;
	}
	ans = (a * mul(b, 1000000005)) % 1000000007;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	cout << cal(n, k);

}