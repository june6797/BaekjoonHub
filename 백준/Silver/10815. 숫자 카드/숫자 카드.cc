#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int M;
	int X;
	vector<int> v1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		v1.push_back(X);
	}
	sort(v1.begin(), v1.end());
	cin >> M;


	for (int i = 0; i < M; i++)
	{
		cin >> X;
		int start = 0;
		int end = v1.size() - 1;
		int a = 0;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (v1[mid] == X)
			{
				a = 1;
				break;
			}
			else if (v1[mid] < X)
			{
				start = mid + 1;
			}
			else if (v1[mid] > X)
			{
				end = mid - 1;
			}
		}

		cout << a << " ";
	}

}