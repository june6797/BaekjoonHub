#include <iostream>
using namespace std;

int Warr[101];
int Varr[101];
int dp[101][100001];

/* 배낭풀기 문제의 가장 기본적 접근법
짐을 쪼갤 수 있는 경우의 배낭문제를 분할가능 배낭문제
짐을 쪼갤 수 없는 경우의 배낭문제를 0-1 배낭문제
이 문제는 0-1 배낭문제
*/

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		int W, V;
		cin >> W >> V;
		Warr[i] = W;
		Varr[i] = V;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (Warr[i] <= j)
			{
				dp[i][j] = max(dp[i - 1][j - Warr[i]] + Varr[i], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}