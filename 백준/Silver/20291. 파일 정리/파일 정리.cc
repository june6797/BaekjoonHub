#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<string, int> m;
vector<string> v;
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
		string temp = "";
		bool flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (flag)
			{
				temp += str[i];
			}
			if (str[i] == '.')
			{
				flag = true;
			}
		}
		if (m.find(temp) == m.end())
		{
			m.insert({ temp, 1 });
			v.push_back(temp);
		}
		else
		{
			m[temp]++;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " " << m[v[i]] << "\n";
	}
}