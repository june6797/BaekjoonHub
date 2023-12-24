#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double sum[21];
int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		vector<double> v;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			double a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		if (N == 1)
		{
			cout << "NO\n";
		}
		else if (N == 2)
		{
			if (v[0] == v[1])
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			bool flag = false;
			for (int i = 1; i <= N; i++)
			{
				sum[i] = sum[i - 1] + v[i - 1];
			}
			for (int i = 3; i <= N; i++)
			{
				if (sum[i - 1] >= v[i - 1])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		for (int i = 0; i <= N; i++)
		{
			sum[i] = 0;
		}
	}
}