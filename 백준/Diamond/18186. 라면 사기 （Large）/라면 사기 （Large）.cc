#include <iostream>

using namespace std;

long long int arr[1000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int N, B, C;
	cin >> N >> B >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	long long int ans = 0;

	if (B < C)
	{
		for (int i = 0; i < N; i++)
		{
			ans += arr[i];
		}
		ans = ans * B;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i + 1] <= arr[i + 2])
			{
				int check = min(arr[i], arr[i + 1]);

				ans += (B + 2 * C) * check;
				arr[i] -= check;
				arr[i + 1] -= check;
				arr[i + 2] -= check;
			}
			else
			{
				int check = min(arr[i], arr[i + 1] - arr[i + 2]);
				ans += (B + C) * check;
				arr[i] -= check;
				arr[i + 1] -= check;

				check = min(arr[i], arr[i + 2]);
				ans += (B + 2 * C) * check;
				arr[i] -= check;
				arr[i + 1] -= check;
				arr[i + 2] -= check;
			}
			ans += B * arr[i];
			arr[i] = 0;
		}
	}
	cout << ans;
}