#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;

vector<int> v[15];
int arr[121];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i < 121; i++)
	{
		arr[i] = i;
	}
	for (int i = 1; i < 121; i++)
	{
		if (i % 20 == 0)
		{
			v[(i - 1) / 8].push_back(20);
		}
		else
		{
			v[(i - 1) / 8].push_back(i % 20);
		}
	}
	for (int i = 0; i < 15; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}