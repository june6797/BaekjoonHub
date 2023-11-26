#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int arr[10];

int findmax(int N) {
	while (N >= 0)
	{
		string str = to_string(N);
		bool find = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (arr[str[i] - '0'] == 1)
			{
				find = false;
				break;
			}
		}
		if (find)
		{
			return N;
		}
		N--;
	}
	return N;
}

int findmin(int N) {
	while (N <= 2000000)
	{
		string str = to_string(N);
		bool find = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (arr[str[i] - '0'] == 1)
			{
				find = false;
				break;
			}
		}
		if (find)
		{
			return N;
		}
		N++;
	}
	return N;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		arr[num] = 1;
	}
	int real = abs(100 - N);
	if (M == 10)
	{
		cout << real;
	}
	else
	{
		int ma = findmax(N);
		int mi = findmin(N);

		if (ma == -1)
		{
			int minminus = mi - N;
			int misize = to_string(mi).size();
			int mians = misize + minminus;
			real = min(real, mians);
		}
		else if (mi == 2000001)
		{
			int maxminus = N - ma;
			int masize = to_string(ma).size();
			int maans = masize + maxminus;
			real = min(real, maans);
		}
		else
		{
			int maxminus = N - ma;
			int minminus = mi - N;
			int masize = to_string(ma).size();
			int misize = to_string(mi).size();
			int maans = masize + maxminus;
			int mians = misize + minminus;
			real = min(real, maans);
			real = min(real, mians);
		}

		cout << real;
	}
}