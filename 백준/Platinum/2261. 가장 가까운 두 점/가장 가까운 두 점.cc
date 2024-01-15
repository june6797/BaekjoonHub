#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}
vector<pair<int, int>> v;
int n;

int dist(pair<int, int> p1, pair<int, int> p2) {
	int x = p1.first - p2.first;
	int y = p1.second - p2.second;
	return x * x + y * y;
}

int divide(int left, int right) {
	int xsize = right - left + 1;
	if (xsize == 2)
	{
		return dist(v[left], v[right]);
	}
	if (xsize == 3)
	{
		int small = min(dist(v[left], v[left + 1]), dist(v[left + 1], v[right]));
		small = min(small, dist(v[left], v[right]));
		return small;
	}

	int mid = (left + right) / 2;
	int ans = min(divide(left, mid), divide(mid + 1, right));

	vector<pair<int, int>> temp;
	int midline = (v[mid].first + v[mid + 1].first) / 2;

	for (int i = left; i <= right; i++)
	{
		if ((midline - v[i].first) * (midline - v[i].first) < ans)
		{
			temp.push_back(v[i]);
		}
	}
	sort(temp.begin(), temp.end(), cmp);
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if ((temp[i].second - temp[j].second) * (temp[i].second - temp[j].second) >= ans)
			{
				break;
			}
			else
			{
				ans = min(ans, dist(temp[i], temp[j]));
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	cout << divide(0, n - 1);

}