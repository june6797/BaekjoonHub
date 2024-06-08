#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

struct dot {
	double x;
	double y;
};

int n;
double ans = 1234567890;
vector<dot> v;
bool picked[21];


void solve(int idx, int pick) {
	if (pick == n / 2)
	{
		double dx = 0;
		double dy = 0;
		for (int i = 0; i < n; i++)
		{
			if (picked[i] == 0)
			{
				dx += v[i].x;
				dy += v[i].y;
			}
			else
			{
				dx -= v[i].x;
				dy -= v[i].y;
			}
		}
		ans = min(ans, sqrt(dx * dx + dy * dy));
	}
	if (idx == n)
	{
		return;
	}

	solve(idx + 1, pick);
	picked[idx] = 1;
	solve(idx + 1, pick + 1);
	picked[idx] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		v.clear();
		ans = 1234567890;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			dot d;
			cin >> d.x >> d.y;
			v.push_back(d);
		}
		solve(0, 0);
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
}
