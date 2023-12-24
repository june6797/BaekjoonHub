#include <iostream>
using namespace std;

int ans = 0;
int fib(int n) {
	if (n == 1 || n == 2) {
		ans++;
		return 1;
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}
int main() {
	int N;
	cin >> N;
	fib(N);
	cout << ans << " " << N - 2;
}