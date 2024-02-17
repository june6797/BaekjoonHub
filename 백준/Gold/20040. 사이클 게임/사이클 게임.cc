#include <iostream>
using namespace std;

int par[500001];
void unionfind(int a, int b) {
	a = par[a];
	b = par[b];
	if (a != b)
	{
		par[b] = a;
	}
}

int find(int a) {
	if (par[a] != a)
	{
		return par[a] = find(par[a]);
	}
	else
	{
		return a;
	}
}
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b))
		{
			if (ans == 0)
			{
				ans = i;
			}
		}
		else
		{
			unionfind(a, b);
		}
	}
	cout << ans;
}