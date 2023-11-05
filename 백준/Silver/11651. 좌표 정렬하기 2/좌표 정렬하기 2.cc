#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y, x });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " " << v[i].first << "\n";
	}
}