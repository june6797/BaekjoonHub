#include <iostream>
#include <cmath>
using namespace std;

int box[20];
long long int ans;
bool flag;
void fillbox(int l, int w, int h) {
	if (l == 0 || w == 0 || h == 0)
	{
		return;
	}
	for (int i = 19; i >= 0; i--)
	{
		if (box[i] > 0)
		{
			int s = 1 << i;
			if (l >= s && w >= s && h >= s)
			{
				ans++;
				box[i]--;
				fillbox(l, s, h - s);
				fillbox(l, w - s, h);
				fillbox(l - s, s, s);
				return;
			}
		}
	}
	flag = true;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, w, h;
	cin >> l >> w >> h;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		box[a] = b;
	}
	fillbox(l, w, h);
	if (flag)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}