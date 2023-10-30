#include <iostream>
#define m 10000001
using namespace std;
long long int arr[m];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int A, B;
	cin >> A >> B;
	for (int i = 2; i < m; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i * i < m; i++)
	{
		if (arr[i])
		{
			for (int j = i * 2; j < m; j = j + i)
			{
				arr[j] = 0;
			}
		}
	}

	long long int ans = 0;

	for (long long int i = 2; i * i <= B; i++)
	{

		if (arr[i])
		{
			long long int a = arr[i];
			while (static_cast<double>(arr[i]) <= static_cast<double>(B) / a)
			{
				if (static_cast<double>(arr[i]) >= static_cast<double>(A) / a)
				{
					ans++;
				}
				a = a * arr[i];
			}

		}
	}
	cout << ans;
}