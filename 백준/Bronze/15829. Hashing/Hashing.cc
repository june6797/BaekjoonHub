#include <iostream>
using namespace std;

int main() {
	int L;
	long long int hash = 0, k = 1;
	cin >> L;
	string str;
	cin >> str;
	for (int i = 0; i < L; i++)
	{
		int a = str[i] - 96;
		hash = (hash + (a * k)) % 1234567891;
		k = (k * 31) % 1234567891;
	}
	cout << hash;
}