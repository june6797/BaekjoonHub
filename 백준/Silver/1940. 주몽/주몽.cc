#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M, num;
	cin >> N >> M;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int start = 0;
	int end = N - 1;
	int ans = 0;
	while (start < end)
	{
		if (arr[start] + arr[end] < M)
		{
			start++;
		}
		else if (arr[start] + arr[end] > M)
		{
			end--;
		}
		else
		{
			start++;
			end--;
			ans++;
		}
	}
	cout << ans;
}