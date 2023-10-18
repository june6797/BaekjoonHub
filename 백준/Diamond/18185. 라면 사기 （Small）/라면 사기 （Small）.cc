#include <iostream>

using namespace std;

long long int arr[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i + 1] <= arr[i + 2])
		{
			int check = min(arr[i], arr[i + 1]);

			ans += 7 * check;
			arr[i] -= check;
			arr[i + 1] -= check;
			arr[i + 2] -= check;
		}
		else
		{
			int check = min(arr[i], arr[i + 1] - arr[i + 2]);
			ans += 5 * check;
			arr[i] -= check;
			arr[i + 1] -= check;

			check = min(arr[i], arr[i + 2]);
			ans += 7 * check;
			arr[i] -= check;
			arr[i + 1] -= check;
			arr[i + 2] -= check;
		}
		ans += 3 * arr[i];
		arr[i] = 0;
	}
	cout << ans;
}