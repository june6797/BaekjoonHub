#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string n, w;
			cin >> n >> w;
			if (m.find(w) != m.end())
			{
				m[w]++;
			}
			else
			{
				m.insert({ w, 1 });
			}
		}
		int ans = 1;
		for (pair<string, int> s : m)
		{
			ans *= (m[s.first] + 1);
		}
		cout << ans - 1 << "\n";
		m.clear();
	}
}