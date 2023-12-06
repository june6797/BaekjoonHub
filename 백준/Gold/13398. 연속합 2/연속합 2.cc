#include <iostream>
using namespace std;
int arr[100001];
int r[100001];
int l[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = -1001;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		r[i] = max(arr[i], r[i - 1] + arr[i]);
		ans = max(ans, r[i]);
	}
	l[n] = arr[n];
	for (int i = n - 1; i >= 1; i--)
	{
		l[i] = max(arr[i], l[i + 1] + arr[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int temp = r[i - 1] + l[i + 1];
		ans = max(ans, temp);
	}
	cout << ans;
}