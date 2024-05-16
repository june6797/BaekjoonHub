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
char arr[501][501];
vector<pair<int, int>> v[25001];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int ans = 0;
bool pass = true;
void solve(int x, int y) {
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int temp = 0;
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < n && ny >= 0 && ny < n
			&& arr[nx][ny] != 'B')
		{
			if (arr[nx][ny] == 'W')
			{
				temp++;
			}
			else if (arr[nx][ny] == '.')
			{
				break;
			}
			nx += dx[i];
			ny += dy[i];
		}
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (arr[nx][ny] == 'B')
			{
				cnt += temp;
			}
		}
	}
	if (cnt > 0)
	{
		pass = false;
		v[cnt].push_back({ x, y });
		ans = max(ans, cnt);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '.')
			{
				solve(i, j);
			}
		}
	}
	if (pass)
	{
		cout << "PASS";
	}
	else
	{
		sort(v[ans].begin(), v[ans].end());
		cout << v[ans][0].second << " " << v[ans][0].first << "\n" << ans;
	}
}