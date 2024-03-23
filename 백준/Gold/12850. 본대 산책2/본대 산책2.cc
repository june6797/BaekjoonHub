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

ll arr[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};
ll temp[8][8];

void mulmatrix(ll a[8][8], ll b[8][8]) {
	ll c[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ll t = 0;
			for (int k = 0; k < 8; k++)
			{
				t += (a[i][k] * b[k][j]);
				t %= 1000000007;
			}
			c[i][j] = t % 1000000007;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = c[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int d;
	cin >> d;
	for (int i = 0; i < 8; i++)
	{
		temp[i][i] = 1;
	}
	while (d != 0)
	{
		if (d % 2 == 1)
		{
			mulmatrix(temp, arr);
			d -= 1;
		}
		mulmatrix(arr, arr);

		d /= 2;
	}
	cout << temp[0][0];
}
