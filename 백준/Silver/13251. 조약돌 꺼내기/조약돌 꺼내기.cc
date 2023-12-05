#include <iostream>
#include <cmath>
using namespace std;

int arr[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, K, cnt = 0;
	double ans = 0;
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> arr[i];
		cnt += arr[i];
	}
	cin >> K;
	for (int i = 1; i <= M; i++)
	{
		if (arr[i] >= K)
		{
			double temp = 1;
			for (int j = 0; j < K; j++)
			{
				temp *= static_cast<double>(arr[i] - j) / (cnt - j);
			}
			ans += temp;
		}
	}

	cout.precision(9);
	cout << ans;

}