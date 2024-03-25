#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int ans, ret = 987654321;
bool arr[10][10];
bool temp[10][10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void push(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= 9 && ny >= 0 && ny <= 9)
		{
			arr[nx][ny] = !arr[nx][ny];
		}
	}
	arr[x][y] = !arr[x][y];
}

bool checklast() {

	for (int i = 0; i < 10; i++)
	{
		if (arr[9][i])
		{
			return false;
		}
	}
	return true;
}
void turnoff() {
	for (int i = 0; i < 1024; i++)
	{
		ans = 0;
		for (int n = 0; n < 10; n++)
		{
			for (int m = 0; m < 10; m++)
			{
				arr[n][m] = temp[n][m];
			}
		}
		int tt = i;
		for (int j = 0; j < 10; j++)
		{
			if (tt % 2 == 1)
			{
				push(0, j);
				ans++;
			}
			tt /= 2;
		}
		for (int k = 1; k < 10; k++)
		{
			for (int l = 0; l < 10; l++)
			{
				if (arr[k - 1][l])
				{
					push(k, l);
					ans++;
				}
			}
		}
		if (checklast())
		{
			ret = min(ret, ans);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 10; i++)
	{
		string str;
		cin >> str;
		for (size_t j = 0; j < 10; j++)
		{
			if (str[j] == 'O')
			{
				arr[i][j] = true;
				temp[i][j] = true;
			}
		}
	}
	turnoff();
	if (ret != 987654321)
	{
		cout << ret;
	}
	else
	{
		cout << "-1";
	}
}