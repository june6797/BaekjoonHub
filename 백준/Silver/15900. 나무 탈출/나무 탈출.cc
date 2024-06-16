#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, ans;
vector<int> v[500001];
bool visited[500001];
void dfs(int start, int depth) {
	visited[start] = 1;
	bool flag = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visited[v[start][i]] == 0)
		{
			dfs(v[start][i], depth + 1);
			flag = false;
		}
	}
	if (flag)
	{
		ans += depth;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	if (ans % 2 == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}