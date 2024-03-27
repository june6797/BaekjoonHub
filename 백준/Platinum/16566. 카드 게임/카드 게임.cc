#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

vector<int> v;
int arr[4000001];

int find(int x) {
	if (arr[x] == x) {
		return x;
	}
	return arr[x] = find(arr[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}
	arr[x] = y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		arr[i] = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		int idx = find(upper_bound(v.begin(), v.end(), num) - v.begin());
		cout << v[idx] << "\n";
		uni(idx, idx + 1);
	}
}