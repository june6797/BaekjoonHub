#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
bool xcmp(Point p1, Point p2) {
	return p1.x < p2.x;
}
bool ycmp(Point p1, Point p2) {
	return p1.y < p2.y;
}
vector<Point> v;
int n;

int dist(Point p1, Point p2) {
	int x = p1.x - p2.x;
	int y = p1.y - p2.y;
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

	vector<Point> temp;
	int midline = (v[mid].x + v[mid + 1].x) / 2;

	for (int i = left; i <= right; i++)
	{
		if ((midline - v[i].x) * (midline - v[i].x) < ans)
		{
			temp.push_back(v[i]);
		}
	}
	sort(temp.begin(), temp.end(), ycmp);
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if ((temp[i].y - temp[j].y) * (temp[i].y - temp[j].y) >= ans)
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
	sort(v.begin(), v.end(), xcmp);
	cout << divide(0, n - 1);

}