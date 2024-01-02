#include <iostream>
using namespace std;

int number[11];
int opcnt[4];
char opis[4] = { '+', '-', '*', '/' };
char op[10];
int maxans = -1234567890, minans = 1234567890;
void DFS(int cnt, int N) {
	if (cnt == N - 1)
	{
		int ans = number[0];
		for (int i = 0; i < N; i++)
		{
			switch (op[i])
			{
			case '+':
				ans += number[i + 1];
				break;
			case '-':
				ans -= number[i + 1];
				break;
			case '*':
				ans *= number[i + 1];
				break;
			case '/':
				ans /= number[i + 1];
				break;
			}

		}
		maxans = max(maxans, ans);
		minans = min(minans, ans);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (opcnt[i] > 0)
		{
			opcnt[i]--;
			op[cnt] = opis[i];
			DFS(cnt + 1, N);
			opcnt[i]++;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> opcnt[i];
	}
	DFS(0, N);
	cout << maxans << "\n" << minans;
}