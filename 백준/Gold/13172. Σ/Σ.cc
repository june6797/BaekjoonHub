#include <iostream>
#include <cmath>
using namespace std;

int mod = 1000000007;
long long int getmod(long long int N, long long int m) {
	if (m == 1)
	{
		return N;
	}
	if (m % 2 == 1)
	{
		return (N * getmod(N, m - 1)) % mod;
	}
	else
	{
		long long int a = getmod(N, m / 2);
		return (a * a) % mod;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	long long int ans = 0;
	for (int i = 0; i < M; i++)
	{
		int N, S;
		cin >> N >> S;
		long long int temp = (S * getmod(N, mod - 2)) % mod;
		ans += temp;
	}
	cout << ans % mod;
}