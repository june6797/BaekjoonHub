#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int rightx1, rightx2, leftx1, leftx2, topy1, topy2, downy1, downy2;
struct square
{
	int x1, y1, x2, y2;
};
square arr[5];

ll ans;
void solve(int k) {
	ll a = 0, b = 0;
	int y1 = leftx1 + k;
	int y2 = leftx2 + k;
	int y3 = rightx1 + k;
	int y4 = rightx2 + k;
	y1 = max(y1, downy2);
	y2 = min(y2, downy1);
	y3 = max(y3, topy2);
	y4 = min(y4, topy1);
	if (y2 >= y1)
	{
		a = y2 - y1 + 1;
	}
	if (y4 >= y3)
	{
		b = y4 - y3 + 1;
	}
	ans += (a * b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 4; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i].x1 = a;
		arr[i].y1 = b;
		arr[i].x2 = c;
		arr[i].y2 = d;
	}
	leftx1 = max(arr[2].x2, arr[3].x2);
	leftx2 = min(arr[2].x1, arr[3].x1);
	rightx1 = max(arr[1].x1, arr[4].x1);
	rightx2 = min(arr[1].x2, arr[4].x2);
	topy1 = min(arr[1].y2, arr[2].y2);
	topy2 = max(arr[1].y1, arr[2].y1);
	downy1 = min(arr[3].y1, arr[4].y1);
	downy2 = max(arr[3].y2 , arr[4].y2);
	for (int i = -100000; i <= 100000; i++)
	{
		solve(i);
	}
	cout << ans;
}