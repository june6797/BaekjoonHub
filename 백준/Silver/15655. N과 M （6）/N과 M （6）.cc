#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int make[8];
int arr[8];
bool visit[8];
vector<int> v;
void DFS(int cnt, int N, int M, int data) {
	if (cnt == M)
	{
		int temp = 0;
		for (int i = 0; i < M; i++)
		{
			cout << make[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false && v[i] > data)
		{
			make[cnt] = v[i];
			visit[i] = true;
			DFS(cnt + 1, N, M, v[i]);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	v.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	DFS(0, N, M, 0);
}