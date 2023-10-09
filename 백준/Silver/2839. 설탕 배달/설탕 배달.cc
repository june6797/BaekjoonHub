#include <iostream>
using namespace std;


int main() {

	int N;
	cin >> N;
	int a = 0;
	int fivenum = 0;
	int threenum = 0;
	while (true)
	{
		if (N % 5 == 0)
		{
			fivenum = N / 5;
			cout << fivenum + threenum;
			break;
		}
		else if (N < 1)
		{
			cout << "-1";
			break;
		}
		N = N - 3;
		threenum++;
	}





}
