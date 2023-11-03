#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (isPrime(num))
		{
			ans++;
		}
	}
	cout << ans;
}