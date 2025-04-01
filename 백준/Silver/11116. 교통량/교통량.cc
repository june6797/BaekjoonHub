#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		int num;
		int ans = 0;
		cin >> m;
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			a.push_back(num);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			b.push_back(num);
		}
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				if (a[i] + 500 == a[j])
				{
					for (int k = 0; k < m; k++)
					{
						if (a[j] + 500 == b[k])
						{
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}