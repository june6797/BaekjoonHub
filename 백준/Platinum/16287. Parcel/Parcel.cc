#include <bits/stdc++.h>
#define mod 1000000009
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

bool check[800001];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = v[i] + v[j];
			if (sum > w)
			{
				continue;
			}
			if (check[w - sum])
			{
				flag = true;
			}
		}
		for (int j = 0; j <= i - 1; j++)
		{
			int sum = v[i] + v[j];
			if (sum < w)
			{
				check[sum] = true;
			}
		}
	}
	if (flag)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}