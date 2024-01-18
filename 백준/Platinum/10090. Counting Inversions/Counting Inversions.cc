#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int ans;
int arr[1000001];
int temp[1000001];

void solve(int s, int e) {
	if (s == e)
	{
		return;
	}
	int mid = (s + e) / 2;
	solve(s, mid);
	solve(mid + 1, e);

	int l = s;
	int r = mid + 1;
	int idx = s;
	long long int tempans = 0;
	while (l <= mid || r <= e)
	{
		//left가 골라지는 경우
		if (l <= mid && (r > e || arr[l] < arr[r]))
		{
			temp[idx] = arr[l];
			idx++;
			l++;
		}
		//right가 골라지는 경우
		else
		{
			temp[idx] = arr[r];
			tempans += mid - l + 1;
			idx++;
			r++;
		}
	}
	for (int i = s; i <= e; i++)
	{
		arr[i] = temp[i];
	}
	ans += tempans;
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
	solve(1, N);
	cout << ans;
}