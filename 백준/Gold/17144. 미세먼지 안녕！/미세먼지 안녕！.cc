#include <iostream>
#include <vector>
using namespace std;

int arr[50][50];
int save[50][50];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
void spread(int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] >= 5)
			{
				int s = arr[i][j] / 5;
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = x_move[k] + i;
					int ny = y_move[k] + j;
					if (nx >= 0 && nx < r && ny >= 0 && ny < c
						&& arr[nx][ny] != -1)
					{
						cnt++;
						save[nx][ny] += s;
					}
				}
				save[i][j] -= cnt * s;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] += save[i][j];
			save[i][j] = 0;
		}
	}

}

void work(int a, int b) {
	int r = v[0].first - 1;
	int c = v[0].second;

	while (r > 0)
	{
		arr[r][c] = arr[r - 1][c];
		r--;
	}
	while (c < b - 1)
	{
		arr[r][c] = arr[r][c + 1];
		c++;
	}
	while (r < v[0].first)
	{
		arr[r][c] = arr[r + 1][c];
		r++;
	}
	while (c > v[0].second + 1)
	{
		arr[r][c] = arr[r][c - 1];
		c--;
	}
	arr[r][c] = 0;

	r = v[1].first + 1;
	c = v[1].second;
	while (r < a - 1)
	{
		arr[r][c] = arr[r + 1][c];
		r++;
	}
	while (c < b - 1)
	{
		arr[r][c] = arr[r][c + 1];
		c++;
	}
	while (r > v[1].first)
	{
		arr[r][c] = arr[r - 1][c];
		r--;
	}
	while (c > v[1].second + 1)
	{
		arr[r][c] = arr[r][c - 1];
		c--;
	}
	arr[r][c] = 0;










}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c, t;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
			{
				v.push_back({ i, j });
			}
		}
	}
	while (t--)
	{
		spread(r, c);

		work(r, c);
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] > 0)
			{
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}