#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int bottom[500001];
int top[500001];
int sum[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, H;
	cin >> N >> H;
	int ans = 9876543210;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int s;
		cin >> s;
		if (i % 2 == 1)
		{
			bottom[s]++;
		}
		else
		{
			top[H + 1 - s]++;
		}
	}
	for (int i = H - 1; i >= 1; i--)
	{
		bottom[i] += bottom[i + 1];
	}
	for (int i = 1; i <= H; i++)
	{
		top[i] += top[i - 1];
		sum[i] = top[i] + bottom[i];
		if (ans > sum[i])
		{
			cnt = 1;
			ans = sum[i];
		}
		else if (ans == sum[i])
		{
			cnt++;
		}
	}
	cout << ans << " " << cnt;
}