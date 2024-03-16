#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int arr[5001];
long long int ansarr[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int a, b, c;
	long long ans = 30000000001;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N - 2; i++)
	{
		a = i;
		b = i + 1;
		c = N - 1;
		while (b < c)
		{
			long long int sum = arr[a] + arr[b] + arr[c];
			if (abs(sum) < ans)
			{
				ans = abs(sum);
				ansarr[0] = arr[a];
				ansarr[1] = arr[b];
				ansarr[2] = arr[c];
			}
			if (sum > 0)
			{
				c--;
			}
			else if (sum < 0)
			{
				b++;
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << ansarr[i] << " ";
	}
}