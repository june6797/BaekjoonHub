#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back({ num, i });
	}
	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, v[i].second - i);

	}

	cout << ans + 1;
}