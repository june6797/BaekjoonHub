#include <iostream>
using namespace std;

int arr[1100000];
int temp[1100000];
int n, k;

void solve(int s, int e, int cnt) {
	if (s >= e)
	{
		return;
	}
	int mid = (s + e) / 2;
	solve(s, mid, cnt * 2);
	solve(mid + 1, e, cnt * 2);

	int left = s;
	int right = mid + 1;
	int idx = s;
	while (left <= mid || right <= e)
	{
		if (left <= mid && (right > e || arr[left] < arr[right]))
		{
			temp[idx] = arr[left];
			idx++;
			left++;
		}
		else
		{
			temp[idx] = arr[right];
			idx++;
			right++;
		}
	}
	for (int i = s; i <= e; i++)
	{
		arr[i] = temp[i];
	}
	if (cnt == k)
	{
		for (int i = s; i <= e; i++)
		{
			cout << arr[i] << " ";
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> k;
	solve(1, n, 1);
}