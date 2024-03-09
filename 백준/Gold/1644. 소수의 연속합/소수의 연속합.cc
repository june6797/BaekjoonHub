#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[4000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 2; i * i <= N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * 2; j <= N; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			v.push_back(i);
		}
	}
	int s = 0, e = 0, sum = 0, ans = 0;

	while (1)
	{
		if (sum > N)
		{
			sum -= v[s];
			s++;
		}
		else if (e == v.size())
		{
			break;
		}
		else
		{
			sum += v[e];
			e++;
		}
		if (sum == N)
		{
			ans++;
		}
	}
	cout << ans;
}