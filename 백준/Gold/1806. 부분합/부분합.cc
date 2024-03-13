#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S;
	cin >> N >> S;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] >= S)
		{
			flag = true;
		}
	}
	int start = 0, end = 0;
	if (flag)
	{
		cout << "1\n";
	}
	else
	{
		int sum = arr[0];
		int ans = 987654321;
		while (end < N)
		{
			if (sum < S)
			{
				end++;
				sum += arr[end];
			}
			else
			{
				ans = min(ans, end - start + 1);
				sum -= arr[start];
				start++;
			}
		}
		if (ans == 987654321)
		{
			cout << "0\n";
		}
		else
		{
			cout << ans;
		}
	}
}