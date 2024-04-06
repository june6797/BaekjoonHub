#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;
//
//struct shark
//{
//	int x;
//	int y;
//	int speed;
//	int d;
//	int z;
//};
//int r, c, m;
//shark arr[101][101];
//vector<pair<pair<int, int>, pair<pair<int, int>, int>>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x = 10000, y = 10000;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		x = min(x, a);
		y = min(y, b);
	}
	cout << min((n / 6 + 1) * x, min(n * y, (n / 6 * x) + (n % 6 * y)));
}
