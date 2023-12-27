#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
unordered_map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		string name, cond;
		cin >> name >> cond;
		if (cond == "enter")
		{
			if (m.find(name) != m.end())
			{
				m[name] = 1;
			}
			else
			{
				v.push_back(name);
				m.insert({ name, 1 });
			}
		}
		else
		{
			m[name] = 0;
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (m[v[i]] == 1)
		{
			cout << v[i] << "\n";
		}
	}
}