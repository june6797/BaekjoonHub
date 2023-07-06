#include <iostream>

using namespace std;

int main() {
	int N, ans = 1, start = 1, end = 1, sum = 1;
	cin >> N;
	while (end != N)
	{
		if (sum == N)
		{
			ans++;
			end++;
			sum = sum + end;
		}
		else if (sum < N)
		{
			end++;
			sum = sum + end;
		}
		else
		{
			sum = sum - start;
			start++;
		}
	}
	cout << ans;

}