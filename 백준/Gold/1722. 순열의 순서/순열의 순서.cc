#include <iostream>
using namespace std;

long long int F[21];
long long int ans[21];
int visit[21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	F[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		F[i] = F[i - 1] * i;
	}
	int q;
	cin >> q;
	if (q == 1)
	{
		long long int k;
		cin >> k;
		for (int i = 1; i <= N; i++)
		{
			int cnt = 1;
			for (int j = 1; j <= N; j++)
			{
				if (visit[j] == 1)
				{
					continue;
				}
				if (F[N - i] < k)
				{
					k -= F[N - i];
				}
				else
				{
					ans[i] = j;
					visit[j] = 1;
					break;
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			cout << ans[i] << " ";
		}
	}
	else if (q == 2)
	{
		long long int a = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> ans[i];
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j < ans[i]; j++)
			{
				if (visit[j] == 0)
				{
					a += F[N - i];
				}
			}
			visit[ans[i]] = 1;
		}
		cout << a + 1;
	}
}