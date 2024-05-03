#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int ans = 0;
		int n;
		cin >> n;
		int n5 = 5;
		while (n5 <= n)
		{
			ans += n / n5;
			n5 *= 5;
		}

		cout << ans << "\n";
	}
}