#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pick[8];
bool visit[8];
int N, M;
vector<int> v;
void DFS(int level, int last) {
	if (level == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << pick[i] << " ";
		}
		cout << "\n";
		return;
	}
	int temp = 0;
	for (int i = last; i < N; i++)
	{
		if (visit[i] == false && v[i] != temp)
		{
			visit[i] = true;
			pick[level] = v[i];
			temp = v[i];
			DFS(level + 1, i);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	DFS(0, 0);
}