#include <iostream>
#include <vector>
using namespace std;

int R, C, maxans = 0;
char arr[21][21];
int ans[21][21];

int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

void DFS(int r, int c, int str[], int a) {
	int str2[26];
	for (int i = 0; i < 26; i++)
	{
		str2[i] = str[i];
	}
	str2[arr[r][c] - 'A'] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x = r + x_move[i];
		int y = c + y_move[i];
		if (x >= 0 && x < R && y >= 0 && y < C
			&& str2[arr[x][y] - 'A'] == 0)
		{
			DFS(x, y, str2, a + 1);
		}
	}
	if (maxans < a)
	{
		maxans = a;
	}
}
int main() {
	int str[26];
	for (int i = 0; i < 26; i++)
	{
		str[i] = 0;
	}
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string str1;
		cin >> str1;
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = str1[j];
		}
	}
	DFS(0, 0, str, 1);

	cout << maxans;
}