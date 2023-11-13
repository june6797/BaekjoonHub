#include <iostream>
using namespace std;
int arr[100001];
int sum[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int ans = -1234556789;
	for (int i = K; i <= N; i++)
	{
		int temp = sum[i] - sum[i - K];
		if (temp > ans)
		{
			ans = temp;
		}
	}
	cout << ans;
}