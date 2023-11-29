#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, int> m;
vector<string> v;

int dist(string a, string b, string c) {
	int d = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
		{
			d++;
		}
		if (a[i] != c[i])
		{
			d++;
		}
		if (b[i] != c[i])
		{
			d++;
		}
	}
	return d;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		bool flag = false;
		int ans = 1234567890;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			if (m.find(str) == m.end())
			{
				m[str] = 1;
				v.push_back(str);
			}
			else if (m[str] == 1)
			{
				m[str]++;
				v.push_back(str);
			}
			else
			{
				flag = true;
				ans = 0;
			}
		}
		if (flag)
		{
			cout << ans << "\n";
		}
		else
		{
			for (int i = 0; i < v.size() - 2; i++)
			{
				for (int j = i + 1; j < v.size() - 1; j++)
				{
					for (int k = j + 1; k < v.size(); k++)
					{
						ans = min(ans, dist(v[i], v[j], v[k]));
					}
				}
			}
			cout << ans << "\n";
		}
		m.clear();
		v.clear();
	}
}