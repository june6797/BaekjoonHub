#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int n;
double arr[10];
bool pick[10];
int cnt;
void solve(int idx) {
	if (idx == n)
	{
		double ans = 0;
		double under = double(99) / 100, up = double(101) / 100;
		for (int i = 0; i < n; i++)
		{
			if (pick[i])
			{
				ans += (1 / arr[i]);
			}
		}
		if (ans >= under && ans <= up)
		{
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		pick[idx] = i;
		solve(idx + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	solve(0);
	cout << cnt;

}