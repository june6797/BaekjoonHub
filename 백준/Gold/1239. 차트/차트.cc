#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n;
int arr[8];
bool visit[8];
int pick[8];
int ans = 0;
void solve(int idx) {
	if (idx == n)
	{
		vector<int > v;
		int temp = 0;
		int tt = 0;
		for (int i = 0; i < n; i++)
		{
			temp += pick[i];
			v.push_back(temp);
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == temp - 50)
				{
					tt++;
				}
			}
		}
		ans = max(ans, tt);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			pick[idx] = arr[i];
			solve(idx + 1);
			visit[i] = 0;
		}
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
	cout << ans;
}