#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> d;
int arr[101][101];
char change[10001];

int main() {
	int N, K, L, ans = 0;
	int x_head = 1, y_head = 1;
	int x_dir = 0, y_dir = 1;

	d.push_front({ 1, 1 });
	arr[1][1] = 1;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 2; //apple location
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int num;
		char s;
		cin >> num >> s;
		change[num] = s;
	}
	while (1)
	{
		ans++;
		x_head += x_dir;
		y_head += y_dir;

		if (x_head <= 0 || x_head >= N + 1
			|| y_head <= 0 || y_head >= N + 1
			|| arr[x_head][y_head] == 1)
		{
			break;
		}

		if (arr[x_head][y_head] != 2)
		{
			arr[d.back().first][d.back().second] = 0;
			d.pop_back();
		}
		d.push_front({ x_head, y_head });
		arr[x_head][y_head] = 1;

		if (change[ans] == 'D') {
			if (x_dir == 0 && y_dir == 1)
			{
				x_dir = 1;
				y_dir = 0;
			}
			else if (x_dir == 1 && y_dir == 0)
			{
				x_dir = 0;
				y_dir = -1;
			}
			else if (x_dir == 0 && y_dir == -1)
			{
				x_dir = -1;
				y_dir = 0;
			}
			else if (x_dir == -1 && y_dir == 0)
			{
				x_dir = 0;
				y_dir = 1;
			}
		}
		else if (change[ans] == 'L')
		{
			if (x_dir == 0 && y_dir == 1)
			{
				x_dir = -1;
				y_dir = 0;
			}
			else if (x_dir == -1 && y_dir == 0)
			{
				x_dir = 0;
				y_dir = -1;
			}
			else if (x_dir == 0 && y_dir == -1)
			{
				x_dir = 1;
				y_dir = 0;
			}
			else if (x_dir == 1 && y_dir == 0)
			{
				x_dir = 0;
				y_dir = 1;
			}
		}
	}


	cout << ans;
}