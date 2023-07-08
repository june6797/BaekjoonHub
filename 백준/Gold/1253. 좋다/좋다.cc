#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, num, result = 0;
	cin >> N;
	vector <int> v;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		long a = v[i];
		int start = 0;
		int end = N - 1;
		while (start < end)
		{
			if (v[start] + v[end] == a)
			{
				if (i != start && i != end)
				{
					result++;
					break;
				}
				else if (i == start)
				{
					start++;
				}
				else if (i == end)
				{
					end--;
				}
			}
			else if (v[start] + v[end] < a)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}
	cout << result;
}