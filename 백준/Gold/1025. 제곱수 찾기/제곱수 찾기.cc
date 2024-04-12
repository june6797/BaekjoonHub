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

int n, m;
int arr[10][10];
bool solve(int num) {
	int a = sqrt(num);
	if (a * a == num)
	{
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int x = -n; x < n; x++)
			{
				for (int y = -m; y < m; y++)
				{
					if (x == 0 && y == 0)
					{
						continue;
					}
					int temp = 0;
					int xx = i, yy = j;
					while (xx >= 0 && xx < n && yy >= 0 && yy < m)
					{
						temp = temp * 10 + arr[xx][yy];
						xx += x;
						yy += y;
						if (solve(temp))
						{
							ans = max(ans, temp);
						}
					}
				}
			}
		}
	}
	cout << ans;
}