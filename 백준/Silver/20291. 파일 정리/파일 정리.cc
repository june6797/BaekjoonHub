#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<string, int> m;
vector<string> v;
int main() {
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