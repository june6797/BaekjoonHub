#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long int, long long int> m;

long long int DFS(long long int N, long long int P, long long int Q) {
	if (N == 0)
	{
		return m[0];
	}
	if (m.find(N) != m.end())
	{
		return m[N];
	}
	return m[N] = DFS(N / P, P, Q) + DFS(N / Q, P, Q);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N, P, Q;
	cin >> N >> P >> Q;
	m.insert({ 0, 1 });
	cout << DFS(N, P, Q);
}