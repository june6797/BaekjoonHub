#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
int visit[1001];

bool isprime(int num) {
	if (num == 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}

	}
	return true;
}

void DFS(int start, int cnt, int N) {
	if (cnt == N)
	{
		cout << start << "\n";
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (isprime(10 * start + i))
		{
			DFS(10 * start + i, cnt + 1, N);
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= 9; i++)
	{
		if (isprime(i))
		{
			DFS(i, 1, N);
		}
	}
}