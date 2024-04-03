#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (v.empty())
		{
			v.push_back(num);
		}
		else
		{
			if (v[v.size() - 1] < num)
			{
				v.push_back(num);
			}
			else
			{
				int start = 0;
				int end = v.size() - 1;
				while (start < end)
				{
					int mid = (start + end) / 2;
					if (v[mid] < num)
					{
						start = mid + 1;
					}
					else
					{
						end = mid;
					}
				}
				v[start] = num;
			}
		}
	}
	cout << N - v.size();
}
