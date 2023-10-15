#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n, num = 9, ans = 0;
	string str;
	vector<int>v;
	cin >> n;
	int arr[26] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			int idx = str.at(i) - 'A';
			arr[idx] += pow(10, str.length() - i - 1);
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
		{
			v.push_back(arr[i]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--)
	{
		ans += v[i] * num;
		num--;
	}
	cout << ans << "\n";
}
