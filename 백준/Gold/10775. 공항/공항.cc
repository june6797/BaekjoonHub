#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <queue>
typedef long long int ll;
using namespace std;

int parent[100001];

int find(int x) {
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G, P, ans = 0;
	cin >> G >> P;
	for (int i = 1; i <= G; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < P; i++)
	{
		int num;
		cin >> num;
		if (find(num) == 0)
		{
			break;
		}
		else
		{
			ans++;
			Union(find(num), find(num) - 1);
		}
	}
	cout << ans;
}
