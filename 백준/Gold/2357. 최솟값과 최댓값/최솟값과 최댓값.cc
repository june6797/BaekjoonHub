#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, m;
int arr[100001];
int maxtree[400001];
int mintree[400001];

int make_maxtree(int node, int start, int end) {
	if (start == end)
	{
		return maxtree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return maxtree[node] = max(make_maxtree(2 * node, start, mid), make_maxtree(2 * node + 1, mid + 1, end));
}

int make_mintree(int node, int start, int end) {
	if (start == end)
	{
		return mintree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return mintree[node] = min(make_mintree(2 * node, start, mid), make_mintree(2 * node + 1, mid + 1, end));
}

int submax(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return maxtree[node];
	}
	int mid = (start + end) / 2;
	return max(submax(2 * node, start, mid, left, right), submax(2 * node + 1, mid + 1, end, left, right));
}

int submin(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
	{
		return 2100000000;
	}
	if (left <= start && end <= right)
	{
		return mintree[node];
	}
	int mid = (start + end) / 2;
	return min(submin(2 * node, start, mid, left, right), submin(2 * node + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	make_maxtree(1, 0, n - 1);
	make_mintree(1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << submin(1, 0, n - 1, a - 1, b-1) << " " << submax(1, 0, n - 1, a - 1, b - 1) << "\n";
	}
}