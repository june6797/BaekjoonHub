#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int pick[7];
vector<int> v;
void DFS(int cnt, int level) {
	if (cnt == level)
	{
		for (int i = 0; i < M; i++)
		{
			cout << pick[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		pick[cnt] = v[i];
		DFS(cnt + 1, level);
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
	DFS(0, M);
}