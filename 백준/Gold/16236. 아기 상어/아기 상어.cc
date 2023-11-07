#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[20][20];
int visit[20][20];
int check[20][20];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, -1, 0, 1 };


int mysize = 2;
int eatcnt = 0;

pair<int, int> BFS(int x, int y, int n) {
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	int howdeep = 0;
	q.push({ x, y });
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (arr[a][b] != 0 && arr[a][b] < mysize)
		{
			if (v.size() == 0)
			{
				howdeep = check[a][b];
				v.push_back({ a, b });
			}
			else
			{
				if (check[a][b] > howdeep)
				{
					break;
				}
				else
				{
					v.push_back({ a, b });
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++)
			{
				int nx = a + x_move[i];
				int ny = b + y_move[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n
					&& visit[nx][ny] == 0 && arr[nx][ny] <= mysize)
				{
					q.push({ nx, ny });
					visit[nx][ny] = 1;
					check[nx][ny] = check[a][b] + 1;
				}
			}
		}
	}
	if (v.size() == 0)
	{
		return { -1, -1 };
	}
	else
	{
		int ra = v.back().first;
		int rb = v.back().second;
		while (!v.empty())
		{
			int na = v.back().first;
			int nb = v.back().second;
			if (na < ra)
			{
				ra = na;
				rb = nb;
			}
			else if (na == ra) {
				if (nb < rb)
				{
					ra = na;
					rb = nb;
				}
			}
			v.pop_back();
		}
		arr[ra][rb] = 0;
		eatcnt++;
		if (mysize == eatcnt)
		{
			mysize++;
			eatcnt = 0;
		}
		return { ra, rb };
	}
}

int main() {
	int N;
	cin >> N;
	int x = 0, y = 0, ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				x = i;
				y = j;
				arr[i][j] = 0;
			}
		}
	}
	pair<int, int> temp = BFS(x, y, N);
	while (temp.first != -1 && temp.second != -1)
	{
		ans += check[temp.first][temp.second];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = 0;
				check[i][j] = 0;
			}
		}
		temp = BFS(temp.first, temp.second, N);
	}
	cout << ans;
}
