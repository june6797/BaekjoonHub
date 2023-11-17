#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[9];

int ans[9];
int temp[9];
void DP(int D) {
	ans[1] = 1;
	for (int t = 1; t <= D; t++)
	{
		for (int i = 1; i < 9; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				temp[i] = (temp[i] + ans[v[i][j]]) % 1000000007;
			}

		}

		for (int i = 1; i <= 9; i++)
		{
			ans[i] = temp[i];
			temp[i] = 0;
		}
	}
}
int main() {
	v[1].push_back(2);
	v[1].push_back(3);

	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);

	v[3].push_back(1);
	v[3].push_back(2);
	v[3].push_back(4);
	v[3].push_back(5);

	v[4].push_back(2);
	v[4].push_back(3);
	v[4].push_back(5);
	v[4].push_back(6);

	v[5].push_back(3);
	v[5].push_back(4);
	v[5].push_back(6);
	v[5].push_back(7);

	v[6].push_back(4);
	v[6].push_back(5);
	v[6].push_back(8);

	v[7].push_back(5);
	v[7].push_back(8);

	v[8].push_back(6);
	v[8].push_back(7);

	int D;
	cin >> D;
	DP(D);
	cout << ans[1];
}
