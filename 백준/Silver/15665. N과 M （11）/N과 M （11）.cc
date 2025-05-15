#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m;
vector<int> v;
bool arr[10001];
int ans[7];
void solve(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		ans[dep] = v[i];
		solve(dep + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (arr[num] == 0) {
			arr[num] = 1;
			v.push_back(num);
		}


	}
	sort(v.begin(), v.end());
	solve(0);
}
