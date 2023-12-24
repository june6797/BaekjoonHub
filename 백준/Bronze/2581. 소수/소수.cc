#include <iostream>
using namespace std;

bool isPrime(int x) {
	if (x == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int main() {
	int M, N, small = 0, sum = 0;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (isPrime(i))
		{
			if (small == 0)
			{
				small = i;
			}
			sum += i;
		}
	}
	if (sum == 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << sum << "\n" << small;
	}
}