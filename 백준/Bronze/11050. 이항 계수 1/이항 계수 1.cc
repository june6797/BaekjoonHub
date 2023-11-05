#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int u = 1, d1 = 1, d2 = 1;
	for (int i = 1; i <= N; i++)
	{
		u *= i;
	}
	for (int i = 1; i <= K; i++)
	{
		d1 *= i;
	}
	for (int i = 1; i <= N - K; i++)
	{
		d2 *= i;
	}
	cout << u / (d1 * d2);
}