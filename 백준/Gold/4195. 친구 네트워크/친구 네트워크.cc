#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<string, int>> m;
string find(string a) {
	if (m[a].first == a)
	{
		return a;
	}
	else
	{
		return m[a].first = find(m[a].first);
	}
}

void unionfind(string a, string b) {
	string aa = find(a);
	string bb = find(b);
	if (aa == bb)
	{
		return;
	}
	else
	{
		m[bb].first = aa;
		m[aa].second += m[bb].second;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		m.clear();
		int F;
		cin >> F;
		string a, b;
		for (int i = 0; i < F; i++)
		{
			cin >> a >> b;
			if (m.find(a) == m.end())
			{
				m.insert({ a, {a, 1} });
			}
			if (m.find(b) == m.end())
			{
				m.insert({ b, {b, 1} });
			}
			unionfind(a, b);
			cout << m[find(a)].second << "\n";
		}
	}
}