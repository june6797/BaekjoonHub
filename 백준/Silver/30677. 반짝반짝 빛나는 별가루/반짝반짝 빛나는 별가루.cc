#include <iostream>
using namespace std;

double base[100001];
double s[100001];
double p[100001];
double skill[100001];
int main() {
	long long int ans = 0;
	double pc = 0, combo = 0;
	bool flag = false;
	double N, K, C, R;
	cin >> N >> K >> C >> R;
	for (int i = 1; i <= K; i++)
	{
		cin >> base[i];
	}
	for (int i = 1; i <= K; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= K; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			pc -= R;
			if (pc < 0)
			{
				pc = 0;
			}
			combo = 0;
		}
		else
		{
			ans += base[num] * ((100 + (combo * C)) / 100)
				* ((100 + (s[num] * skill[num])) / 100);

			skill[num] += 1;
			combo++;
			pc += p[num];
			if (pc > 100)
			{
				flag = true;
				break;
			}
		}
	}
	if (flag)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}