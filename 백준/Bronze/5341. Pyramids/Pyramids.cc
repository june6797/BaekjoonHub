#include <iostream>
using namespace std;

int main() {
	int N;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
		}
		cout << N * (N + 1) / 2 << "\n";
	}
}