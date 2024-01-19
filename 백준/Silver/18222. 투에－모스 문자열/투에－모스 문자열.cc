#include <iostream>
#include <cmath>
using namespace std;

int box[20];
long long int ans;
bool flag;
int n;

void solve(long long int n, int cnt) {
	if (n == 1)
	{
		if (cnt % 2 == 1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return;
	}
	long long int s = 1;
	while (s < n)
	{
		s *= 2;
	}
	s /= 2;
	solve(n - s, cnt + 1);
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin >> n;
	solve(n, 0);

}