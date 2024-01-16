#include <iostream>
using namespace std;

void moo(int n, int k, int l) {
	if (n <= 3) {
		if (n == 1)
		{
			cout << "m";
		}
		else
		{
			cout << "o";
		}
		return;
	}
	int len = l * 2 + k + 3;
	if (len < n)
	{
		moo(n, k + 1, len);
	}
	else
	{
		if (n > l && n <= (l + k + 3))
		{
			if (n == (l + 1))
			{
				cout << "m";
			}
			else
			{
				cout << "o";
			}
		}
		else
		{
			moo(n - (l + k + 3), 1, 3);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	moo(n, 1, 3);
}