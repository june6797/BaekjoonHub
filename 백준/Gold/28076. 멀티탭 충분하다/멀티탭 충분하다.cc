#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;

vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<int>());
	if (n == 1)
	{
		cout << v[0];
	}
	else if (n == 2)
	{
		cout << v[0] + v[1] - 1;
	}
	else
	{
		int ans = v[0];
		int first = 0;
		int second = 0;
		if (n % 3 == 0)
		{
			first = n / 3;
			second = n / 3 * 2;
		}
		else if (n % 3 == 1)
		{
			first = n / 3 + 1;
			second = n / 3 * 2 + 1;
		}
		else
		{
			first = n / 3 + 1;
			second = n / 3 * 2 + 2;
		}
		cout << ans + v[first] + v[second] - 3;
	}
}