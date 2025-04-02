#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> v[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cout << n - 1 << "\n";
	}
}