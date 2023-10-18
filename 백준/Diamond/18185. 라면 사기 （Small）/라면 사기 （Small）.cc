#include <iostream>

using namespace std;

int arr[10003];

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
			while (arr[i] != 0 && arr[i + 1] != 0 && arr[i + 2] != 0)
			{
				ans += 7;
				arr[i] -= 1;
				arr[i + 1] -= 1;
				arr[i + 2] -= 1;
			}
			while (arr[i] != 0)
			{
				ans += 3;
				arr[i] -= 1;
			}
		}
		else
		{
			while (arr[i] != 0 && arr[i + 1] != arr[i + 2])
			{
				ans += 5;
				arr[i] -= 1;
				arr[i + 1] -= 1;
			}
			while (arr[i] != 0 && arr[i + 1] != 0 && arr[i + 2] != 0)
			{
				ans += 7;
				arr[i] -= 1;
				arr[i + 1] -= 1;
				arr[i + 2] -= 1;
			}
			while (arr[i] != 0)
			{
				ans += 3;
				arr[i] -= 1;
			}
		}

	}
	cout << ans;
}