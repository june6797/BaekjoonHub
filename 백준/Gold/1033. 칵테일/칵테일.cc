#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector <tuple<int, int, int>> v[10];
int visit[10];
long long int ans[10];

long long int gcd(long long int p, long long int q) {
	if (q == 0)
	{
		return p;
	}
	else
	{
		return gcd(q, p % q);
	}
}

void DFS(int start) {
	visit[start] = 1;
	for (tuple<int, int, int> i : v[start])
	{
		int next = get<0>(i);
		if (!visit[next])
		{
			ans[next] = ans[start] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	long long int m = 1;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		v[a].push_back({ b, p, q });
		v[b].push_back({ a, q, p });
		m *= p * q / gcd(p, q);
	}
	ans[0] = m;
	DFS(0);

	for (int i = 1; i < N; i++)
	{
		m = gcd(m, ans[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] / m << " ";
	}
}