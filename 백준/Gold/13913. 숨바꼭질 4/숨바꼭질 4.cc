#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, k;
bool visit[100001];
int arr[100001];
void BFS(int x) {
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty())
	{
		int tx = q.front();
		if (tx == k)
		{
			break;
		}
		q.pop();

		if (tx * 2 >= 0 && tx * 2 <= 100000 && visit[tx * 2] == false)
		{
			visit[tx * 2] = 1;
			q.push(tx * 2);
			arr[tx * 2] = tx;
		}

		if (tx + 1 >= 0 && tx + 1 <= 100000 && visit[tx + 1] == false)
		{
			visit[tx + 1] = 1;
			q.push(tx + 1);
			arr[tx + 1] = tx;
		}

		if (tx - 1 <= 100000 && tx - 1 >= 0 && visit[tx - 1] == false)
		{
			visit[tx - 1] = 1;
			q.push(tx - 1);
			arr[tx - 1] = tx;
		}


	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < 100001; i++)
	{
		arr[i] = -1;
	}
	BFS(n);
	vector<int> v;
	v.push_back(k);
	while (arr[k] != -1)
	{
		v.push_back(arr[k]);
		k = arr[k];
	}
	cout << v.size() - 1 << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[v.size() - i - 1] << " ";
	}
}