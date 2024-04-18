#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int arr[1000001];
int b, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> b >> c;


	for (int i = 0; i < n; i++)
	{
		arr[i] -= b;
		ans++;
	}
	if (b < c)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				if (arr[i] % c == 0)
				{
					ans += (arr[i] / c);
				}
				else
				{
					ans += ((arr[i] / c) + 1);
				}
			}
		}
		cout << ans;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				if (arr[i] % c == 0)
				{
					ans += (arr[i] / c);
				}
				else
				{
					ans += ((arr[i] / c) + 1);
				}
			}
		}
		cout << ans;
	}

}