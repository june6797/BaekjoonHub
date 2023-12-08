#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> v;
vector<int> ans;
unordered_map<string, int> ma;
int visit[9];
void DFS(int start, int n, int d, int m) {
	if (d == m)
	{
		string str;
		for (int i = 0; i < ans.size(); i++)
		{
			str += to_string(ans[i]) + " ";
		}
		if (ma.find(str) == ma.end())
		{
			ma.insert({ str, 0 });
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << " ";
				str += to_string(ans[i]) + " ";

			}
			cout << "\n";
		}

		return;
	}
	for (int i = start; i < n; i++)
	{
		ans.push_back(v[i]);
		DFS(i, n, d + 1, m);
		ans.pop_back();
		visit[i] = 0;

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