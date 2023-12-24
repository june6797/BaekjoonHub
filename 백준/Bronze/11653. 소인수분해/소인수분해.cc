#include <iostream>
using namespace std;

int main() {
	int N, start = 2;
	cin >> N;
	while (N != 1)
	{
		while (N % start == 0)
		{
			cout << start << "\n";
			N /= start;
		}
		start++;
	}
}