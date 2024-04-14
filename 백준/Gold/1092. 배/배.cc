#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
vector<int> v, box;
int N, M, num;
int take[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		box.push_back(num);
	}
	sort(v.begin(), v.end(), cmp);
	sort(box.begin(), box.end(), cmp);
	if (box[0] > v[0])
	{
		cout << -1;
	}
	else
	{
		int ans = 0;
		while (true)
		{
			bool flag = false;
			for (int i = 0; i < v.size(); i++)
			{
				bool flag2 = false;
				for (int j = 0; j < M; j++)
				{
					if (take[j] == 0 && box[j] <= v[i])
					{
						take[j] = 1;
						flag = true;
						flag2 = true;
						break;
					}
				}
				if (!flag2)
				{
					break;
				}
			}
			if (!flag)
			{
				break;
			}
			ans++;
		}
		cout << ans;
	}
}