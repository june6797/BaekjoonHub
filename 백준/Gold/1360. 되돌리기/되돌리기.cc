#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

vector<pair<string, int>> v;
string cal(int tt) {
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i].second < tt)
		{
			return v[i].first;
		}
	}
	return "";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		int t;
		if (str == "type")
		{
			string a;
			cin >> a;
			cin >> t;
			if (v.size() != 0)
			{
				string temp = v.back().first + a;
				v.push_back({ temp, t });
			}
			else
			{
				v.push_back({ a, t });
			}
		}
		else
		{
			int back;
			cin >> back >> t;
			v.push_back({ cal(t - back), t });
		}
	}
	cout << v.back().first;
}
