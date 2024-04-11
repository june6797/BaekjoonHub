#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;

int n, m, k;
int arr[2002][2002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
			{
				ans++;
			}
		}
	}
		if (ans == 2 * k)
		{
			cout << 0;
		}
		else
		{
			int x = 0, y = 0;
			cout << 2 * k - ans << "\n";
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (arr[i][j])
					{
						x = i;
						y = j;
						break;
					}
				}
				if (x)
				{
					break;
				}
			}
			int r = y + k - 1;
			int d = x + k - 1;
			if (r <= m && arr[x][r] == 1)
			{
				for (int i = y; i <= r; i++)
				{
					if (arr[x + 1][i] == 1)
					{
						cout << x << " " << i << "\n";
						exit(0);
					}
				}
			}
			else if (d <= n && arr[d][y] == 1)
			{
				for (int i = x; i <= d; i++)
				{
					if (y - 1 > 0 && arr[i][y - 1] == 1)
					{
						cout << i << " " << y << "\n";
						exit(0);
					}
					if (y + 1 <= m && arr[i][y + 1] == 1)
					{
						cout << i << " " << y << "\n";
						exit(0);
					}
				}
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (arr[i][j])
					{
						x = i;
						y = j;
						break;
					}
				}
				if (x)
				{
					break;
				}
			}
			if (r <= m && arr[x][r] == 1)
			{
				int last = r;
				while (arr[x][last] == 1)
				{
					last++;
				}
				int start = last - k;
				for (int i = start; i <= r; i++)
				{
					cout << x << " " << i << "\n";
				}
			}
			else
			{
				int last = d;
				while (arr[last][y] == 1)
				{
					last++;
				}
				int start = last - k;
				for (int i = start; i <= d; i++)
				{
					cout << i << " " << y << "\n";
				}
			}
		}
	
}