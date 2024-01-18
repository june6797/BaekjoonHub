#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int arr[100001];

long long int sel(int s, int e) {
	if (s == e)
	{
		return arr[s] * arr[s];
	}
	int mid = (s + e) / 2;
	long long int left = sel(s, mid);
	long long int right = sel(mid + 1, e);

	long long int ans = max(left, right);
	int l = mid;
	int r = mid + 1;

	long long int sum = arr[l] + arr[r];
	long long int minv = min(arr[l], arr[r]);
	ans = max(ans, sum * minv);
	while (s < l || r < e)
	{
		if (r < e && (l == s || arr[r + 1] > arr[l - 1]))
		{
			r += 1;
			sum += arr[r];
			minv = min(minv, arr[r]);
		}
		else
		{
			l -= 1;
			sum += arr[l];
			minv = min(minv, arr[l]);
		}
		ans = max(ans, minv * sum);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cout << sel(1, N);
}