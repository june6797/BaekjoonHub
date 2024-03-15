#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = N - 1;
	int ans = abs(arr[start] + arr[end]);
	int ansleft = arr[start];
	int ansright = arr[end];
	while (start < end)
	{
		int temp = arr[start] + arr[end];
		if (abs(temp) < ans)
		{
			ans = abs(temp);
			ansleft = arr[start];
			ansright = arr[end];
		}
		if (temp > 0)
		{
			end--;
		}
		else if (temp < 0)
		{
			start++;
		}
		else
		{
			cout << ansleft << " " << ansright << "\n";
			exit(0);
		}
	}
	cout << ansleft << " " << ansright << "\n";
}