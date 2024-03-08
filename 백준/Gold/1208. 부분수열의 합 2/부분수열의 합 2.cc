#include <iostream>
#include <map>
using namespace std;

int arr[41];
long long int ans = 0;
int N, S;
map<int, int> m;
void left(int start, int sum, int end) {
	if (start == end)
	{
		m[sum]++;
		return;
	}
	left(start + 1, sum, end);
	left(start + 1, sum + arr[start], end);
}
void right(int start, int sum, int end) {
	if (start == end)
	{
		ans += m[S - sum];
		return;
	}
	right(start + 1, sum, end);
	right(start + 1, sum + arr[start], end);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	left(0, 0, N / 2);
	right(N / 2, 0, N);
	if (S == 0)
	{
		cout << ans - 1;
	}
	else
	{
		cout << ans;
	}
}