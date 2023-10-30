#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int l, r;
	cin >> l >> r;
	for (long long int i = 2; i * i <= r; i++)
	{
		long long int temp = i * i;
		long long int start = l / temp;
		if (l % temp != 0)
		{
			start++;
		}

		for (long long int j = start; j * temp <= r; j++)
		{
			arr[(j * temp) - l] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= r - l; i++)
	{
		if (arr[i] == 0)
		{
			ans++;
		}
	}
	cout << ans;
}