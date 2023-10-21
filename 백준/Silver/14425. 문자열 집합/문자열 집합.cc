#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, string> m;
int main() {
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		m.insert({ str, str });
	}
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (m.find(str) != m.end())
		{
			ans++;
		}
	}
	cout << ans;
}