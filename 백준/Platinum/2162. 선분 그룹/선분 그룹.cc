#include <iostream>
using namespace std;
typedef long long int lli;

int parent[3001];
int line[3001][4];
lli CCW(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3) {
	lli t = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (t > 0)
	{
		return 1;
	}
	else if (t < 0)
	{
		return -1;
	}
	return 0;
}

bool isCross(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3, lli x4, lli y4) {
	lli abc = CCW(x1, y1, x2, y2, x3, y3);
	lli abd = CCW(x1, y1, x2, y2, x4, y4);
	lli cda = CCW(x3, y3, x4, y4, x1, y1);
	lli cdb = CCW(x3, y3, x4, y4, x2, y2);
	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (max(x1, x2) >= min(x3, x4) && max(x3, x4) >= min(x1, x2)
			&& max(y1, y2) >= min(y3, y4) && max(y3, y4) >= min(y1, y2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (abc * abd <= 0 && cda * cdb <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int find(int x) {
	if (parent[x] < 0)
	{
		return x;
	}
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
	{
		return;
	}
	parent[fx] += parent[fy];
	parent[fy] = fx;
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = -1;
		for (int j = 0; j < 4; j++)
		{
			cin >> line[i][j];
		}
		for (int j = 1; j < i; j++)
		{
			if (isCross(line[i][0], line[i][1], line[i][2], line[i][3],
				line[j][0], line[j][1], line[j][2], line[j][3]))
			{
				Union(i, j);
			}
		}
	}
	int ans = 0, res = 0;
	for (int i = 1; i <= N; i++)
	{
		if (parent[i] < 0)
		{
			ans++;
			res = min(res, parent[i]);
		}
	}
	cout << ans << "\n" << -res;
}