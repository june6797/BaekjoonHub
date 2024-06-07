#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, m;
int arr[10001];

bool solve(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= mid)
		{
			sum += arr[i];
		}
		else
		{
			sum += mid;
		}
	}
	return sum <= m;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ma = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ma = max(ma, arr[i]);
	}
	cin >> m;
	int lo = 0, hi = ma + 1;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (solve(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo;


}
