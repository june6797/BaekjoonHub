#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		if (M == 1)
		{
			cout << y << "\n";
		}
		else if (N == 1)
		{
			cout << x << "\n";
		}
		else
		{
			bool flag = false;
			for (int i = 0; i <= N; i++)
			{
				if ((i * M + x) % N == 0 && N == y)
				{
					cout << i * M + x << "\n";
					flag = true;
					break;
				}
				else if ((i * M + x) % N == y)
				{
					cout << i * M + x << "\n";
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << -1 << "\n";
			}
		}
	}
}