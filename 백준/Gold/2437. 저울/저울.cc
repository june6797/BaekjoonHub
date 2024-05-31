#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#define mod 1000000007;
typedef long long ll;
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
	sort(v.begin(), v.end());
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (ans >= v[i])
		{
			ans += v[i];
		}
	}
	cout << ans;
}