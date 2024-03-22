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

ll arr[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	ll M, small = 99999999999999;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (small > arr[i])
		{
			small = arr[i];
		}
	}
	while (small <= M)
	{
		ll a = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] <= M)
			{
				a += arr[i];
				M -= arr[i];
			}
		}

		M = M % a;
	}
	cout << M;
}
