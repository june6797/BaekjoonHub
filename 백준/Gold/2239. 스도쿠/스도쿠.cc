#include <iostream>
#include <vector>
using namespace std;

int sudo[9][9];
vector<pair<int, int>> v;
bool can(int x, int y) {
	for (int i = 0; i < 9; i++)
	{
		if (sudo[x][y] == sudo[x][i] && y != i)
		{
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (sudo[x][y] == sudo[i][y] && x != i)
		{
			return false;
		}
	}
	int nx = x / 3 * 3;
	int ny = y / 3 * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sudo[x][y] == sudo[nx + i][ny + j] && x != nx + i && y != ny + j)
			{
				return false;
			}
		}
	}
	return true;
}
bool DFS(int cnt, int level) {
	if (cnt == level)
	{
		return true;
	}

	int x = v[cnt].first;
	int y = v[cnt].second;
	for (int i = 1; i <= 9; i++)
	{
		sudo[x][y] = i;
		if (can(x, y))
		{
			if (DFS(cnt + 1, level))
			{
				return true;
			}
		}
		sudo[x][y] = 0;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int blank = 0;
	string str;
	for (int i = 0; i < 9; i++)
	{
		cin >> str;
		for (int j = 0; j < 9; j++)
		{
			sudo[i][j] = str[j] - '0';
			if (sudo[i][j] == 0)
			{
				v.push_back({ i, j });
				blank++;
			}
		}
	}
	DFS(0, blank);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudo[i][j];
		}
		cout << "\n";
	}
}