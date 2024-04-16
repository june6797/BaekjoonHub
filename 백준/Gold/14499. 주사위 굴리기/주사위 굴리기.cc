#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;

int n, m, x, y, k;
int arr[20][20];
int dice[6];
int mo[6] = { 1, 6, 4, 3, 5, 2 }; //아래 위 왼 오 앞 뒤

void solve(int num) {
	if (num == 1) //동
	{
		if (y < m - 1)
		{
			y++;
			int temp = mo[0];
			mo[0] = mo[3];
			mo[3] = mo[1];
			mo[1] = mo[2];
			mo[2] = temp;
			if (arr[x][y] == 0)
			{
				arr[x][y] = dice[mo[0]];
			}
			else
			{
				dice[mo[0]] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[mo[1]] << "\n";
		}
	}
	else if (num == 2) //서
	{
		if (y > 0)
		{
			y--;
			int temp = mo[0];
			mo[0] = mo[2];
			mo[2] = mo[1];
			mo[1] = mo[3];
			mo[3] = temp;
			if (arr[x][y] == 0)
			{
				arr[x][y] = dice[mo[0]];
			}
			else
			{
				dice[mo[0]] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[mo[1]] << "\n";
		}
	}
	else if (num == 3) //북
	{
		if (x > 0)
		{
			x--;
			int temp = mo[0];
			mo[0] = mo[5];
			mo[5] = mo[1];
			mo[1] = mo[4];
			mo[4] = temp;
			if (arr[x][y] == 0)
			{
				arr[x][y] = dice[mo[0]];
			}
			else
			{
				dice[mo[0]] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[mo[1]] << "\n";
		}
	}
	else if (num == 4) //남
	{
		if (x < n - 1)
		{
			x++;
			int temp = mo[0];
			mo[0] = mo[4];
			mo[4] = mo[1];
			mo[1] = mo[5];
			mo[5] = temp;
			if (arr[x][y] == 0)
			{
				arr[x][y] = dice[mo[0]];
			}
			else
			{
				dice[mo[0]] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[mo[1]] << "\n";
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		solve(num);
	}
}