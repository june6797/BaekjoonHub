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
#include <stack>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int comb[53][53];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 53; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0 || i == j)
			{
				comb[i][j] = 1;
			}
			else
			{
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 10007;
			}
		}
	}
	cin >> n;
	int cnt = n / 4;
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (i % 2 == 1)
		{
			ans = (ans + comb[13][i] * comb[52 - 4 * i][n - 4 * i]) % 10007;
		}
		else
		{
			ans = (ans - (comb[13][i] * comb[52 - 4 * i][n - 4 * i]) % 10007 + 10007) % 10007;
		}
	}
	cout << ans;
}