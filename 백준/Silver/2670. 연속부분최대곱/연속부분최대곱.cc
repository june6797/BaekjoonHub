#include <iostream>
using namespace std;

double dp[10001];
double num[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(3);
	cout << fixed;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	double ans = num[1];
	for (int i = 1; i <= N; i++)
	{
		double s = 1;
		for (int j = i; j <= N; j++)
		{
			s *= num[j];
			ans = max(ans, s);
		}
	}
	cout << ans;
}