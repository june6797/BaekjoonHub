#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int arr[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
vector<int> v1;
vector<int> s;
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void BFS(int i, int j, int N, int M, int idx) {
	q.push({ i, j });
	int ans = 1;
	arr[i][j] = idx;
	visited[i][j] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_next = x + x_move[i];
			int y_next = y + y_move[i];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M
				&& arr[x_next][y_next] == 0 && visited[x_next][y_next] == 0)
			{
				visited[x_next][y_next] = 1;
				arr[x_next][y_next] = idx;
				q.push({ x_next, y_next });
				ans++;
			}

		}
	}

	v1.push_back(ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	v1.push_back(0);
	int N, M;
	string str;
	int idx = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j) - '0';
			if ((str.at(j) - '0') == 0)
			{
				v.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				BFS(i, j, N, M, idx);
				idx--;
			}

		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				for (int idx = 0; idx < 4; idx++) {
					int x_next = i + x_move[idx];
					int y_next = j + y_move[idx];

					if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M)
					{
						int a = -(arr[x_next][y_next]);
						if (!s.empty())
						{
							for (int k = 0; k < s.size(); k++)
							{
								if (s[k] == a)
								{
									a = 0;
									break;
								}
							}
							s.push_back(a);
						}
						else
						{
							s.push_back(a);
						}
						if (a >= 0)
						{
							arr[i][j] += v1[a];
						}
					}
				}
			}
			s.clear();
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		arr[v[i].first][v[i].second] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j]>= 10)
			{
				cout << (arr[i][j] % 10);
			}
			else
			{
				cout << arr[i][j];
			}
		}
		cout << "\n";
	}
}