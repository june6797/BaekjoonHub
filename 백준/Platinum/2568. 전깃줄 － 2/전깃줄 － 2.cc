#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
vector<int> binary, sequence, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	binary.push_back(v[0].second);
	sequence.push_back(0);

	for (int i = 1; i < N; i++)
	{
		int temp = v[i].second;
		if (binary.back() < temp)
		{
			binary.push_back(temp);
			sequence.push_back(binary.size() - 1);
		}
		else
		{
			int left = 0;
			int right = binary.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (binary[mid] < temp)
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			binary[left] = temp;
			sequence.push_back(left);
		}
	}
	cout << v.size() - binary.size() << "\n";
	int ss = binary.size() - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (sequence[i] == ss)
		{
			ss--;
		}
		else
		{
			ans.push_back(v[i].first);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}