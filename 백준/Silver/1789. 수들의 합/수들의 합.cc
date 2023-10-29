#include <iostream>
using namespace std;
int main() {
	long long int S;
	cin >> S;
	S = 2 * S;
	long long int i = 0;
	while (i * (i + 1) <= S)
	{
		i++;
	}
	cout << i - 1;
}