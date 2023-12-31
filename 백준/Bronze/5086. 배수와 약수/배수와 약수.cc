#include <iostream>
#include <unordered_map>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		else
		{
			if (a > b)
			{
				if (a % b == 0)
				{
					cout << "multiple\n";
				}
				else
				{
					cout << "neither\n";
				}
			}
			else
			{
				if (b % a == 0)
				{
					cout << "factor\n";
				}
				else
				{
					cout << "neither\n";
				}
			}
		}
	}
}