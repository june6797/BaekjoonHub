#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, ans;
	cin >> n;
	ans = n;
	for (long long int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = ans - ans / i;
			while (n % i == 0)
			{
				n = n / i;
			}
		}
	}
	if (n > 1)
	{
		ans = ans - ans / n;
	}
	cout << ans;
}