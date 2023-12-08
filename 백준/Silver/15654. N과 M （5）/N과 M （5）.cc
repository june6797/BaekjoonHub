#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ans;
int visit[9];
void DFS(int start, int n, int d, int m) {
	if (d == m)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			ans.push_back(v[i]);
			DFS(i, n, d + 1, m);
			ans.pop_back();
			visit[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	DFS(0, n, 0, m);

}