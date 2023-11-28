#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
string arr[10001];
int visit[10001];
void BFS(int start, int end) {
	if (start == end)
	{
		return;
	}
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		int d = t * 2 % 10000;
		int s = t - 1;
		if (s == -1)
		{
			s = 9999;
		}
		int l = (t * 10 + t / 1000) % 10000;
		int r = t / 10 + t % 10 * 1000;
		if (visit[d] == 0 || arr[t].size() + 1 < arr[d].size())
		{
			visit[d] = 1;
			arr[d] = arr[t] + "D";
			q.push(d);
		}
		if (visit[s] == 0 || arr[t].size() + 1 < arr[s].size())
		{
			visit[s] = 1;
			arr[s] = arr[t] + "S";
			q.push(s);
		}
		if (visit[l] == 0 || arr[t].size() + 1 < arr[l].size())
		{
			visit[l] = 1;
			arr[l] = arr[t] + "L";
			q.push(l);
		}
		if (visit[r] == 0 || arr[t].size() + 1 < arr[r].size())
		{
			visit[r] = 1;
			arr[r] = arr[t] + "R";
			q.push(r);
		}

	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a, b;
		cin >> a >> b;
		BFS(a, b);
		cout << arr[b] << "\n";
		for (int i = 0; i < 10001; i++)
		{
			arr[i] = "";
			visit[i] = 0;
		}
	}
}