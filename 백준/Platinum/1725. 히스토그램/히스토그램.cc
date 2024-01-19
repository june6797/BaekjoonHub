#include <iostream>
using namespace std;

long long int arr[100001];

long long int solve(int s, int e) {
	if (s == e)
	{
		return arr[s];
	}
	int mid = (s + e) / 2;
	long long int ans = max(solve(s, mid), solve(mid + 1, e));
	long long int left = mid;
	long long int right = mid + 1;
	long long int height = min(arr[left], arr[right]);
	ans = max(ans, 2 * height);
	while (s < left || right < e)
	{
		if (s < left && (right == e || arr[left - 1] > arr[right + 1]))
		{
			left--;
			height = min(height, arr[left]);
		}
		else
		{
			right++;
			height = min(height, arr[right]);
		}
		ans = max(ans, (right - left + 1) * height);
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
	cout << solve(1, N) << "\n";

}