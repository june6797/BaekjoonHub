#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (m.find(str) == m.end())
		{
			m.insert({ str, 1 });
		}
		else
		{
			m[str]++;
		}
	}
	map<string, int>::iterator iter;
	string ans;
	int cnt = 0;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (cnt < iter->second)
		{
			ans = iter->first;
			cnt = iter->second;
		}
	}
	cout << ans;
}