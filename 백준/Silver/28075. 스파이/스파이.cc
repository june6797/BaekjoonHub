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
int inf[6], pick[6];
int n, m, ans;

void solve(int idx) {
	if (idx == n)
	{
		int score = inf[pick[0]];
		for (int i = 1; i < n; i++)
		{
			if ((pick[i] % 3) == (pick[i - 1] % 3))
			{
				score += (inf[pick[i]] / 2);
			}
			else
			{
				score += inf[pick[i]];
			}
		}
		if (score >= m)
		{
			ans++;
		}
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		pick[idx] = i;
		solve(idx + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 6; i++)
	{
		cin >> inf[i];
	}
	solve(0);
	cout << ans;
}