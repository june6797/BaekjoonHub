#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n;
bool visited[20001];

void bfs() {
	queue<pair<int, string>> q;
	q.push({ 1, "1" });
	visited[1] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		string temp = q.front().second;
		q.pop();
		if (x % n == 0)
		{
			cout << temp << "\n";
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int temp_mod = (10 * x + i) % n;
			if (visited[temp_mod] == 0)
			{
				visited[temp_mod] = 1;
				q.push({ temp_mod, temp + to_string(i) });
			}
		}
	}
	cout << "BRAK\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		bfs();
		memset(visited, 0, sizeof(visited));
	}
}