#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, num;
	cin >> N >> M;
	int start = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (start < num)
		{
			start = num;
		}
		v.push_back(num);
		end += num;
	}
	while (start <= end)
	{
		int m = (start + end) / 2;
		int cnt = 1;
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (sum + v[i] > m)
			{
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}

		if (cnt <= M)
		{
			end = m - 1;
		}
		else
		{
			start = m + 1;
		}
	}
	cout << start;
}