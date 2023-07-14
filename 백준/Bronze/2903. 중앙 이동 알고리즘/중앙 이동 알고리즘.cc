#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a = 2;
	for (int i = 0; i < N; i++)
	{
		a = a + a - 1;
	}
	cout << a * a;

}