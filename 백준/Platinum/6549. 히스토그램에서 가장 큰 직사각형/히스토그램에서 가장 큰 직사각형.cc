#include <iostream>
#include <vector>
using namespace std;

long long int arr[100005];
vector <int> s;

int main() {
	while (1)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		long long ans = 0;
		s.push_back(0);
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= N + 1; i++)
		{
			while (!s.empty() && arr[s.back()] > arr[i])
			{
				int h = s.back();
				s.pop_back();
				int l = i - s.back() - 1;
				ans = max(ans, arr[h] * l);
			}
			s.push_back(i);
		}
		cout << ans << "\n";


		for (int i = 0; i < 100005; i++)
		{
			arr[i] = 0;
		}
		s.clear();
	}
}