#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, int> ma;
int arr1[1001];
int arr2[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, m;
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = arr1[i];
		ma[sum]++;
		for (int j = i + 1; j < n; j++)
		{
			sum += arr1[j];
			ma[sum]++;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < m; i++)
	{
		sum = arr2[i];
		ans += ma[T - sum];
		for (int j = i + 1; j < m; j++)
		{
			sum += arr2[j];
			ans += ma[T - sum];
		}
	}
	cout << ans;
}