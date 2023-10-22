#include <iostream>
using namespace std;

int arr[1001];
int b[1001];
int s[1001];
int ans[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		for (int j = 0; j < i; j++)
		{
			if (num > arr[j])
			{
				b[i] = max(b[i], b[j] + 1);
			}
			else if (num < arr[j])
			{
				s[i] = max(s[i], ans[j] + 1);
			}
		}
		ans[i] = max(b[i], s[i]);
	}

	int a = 0;
	for (int i = 1; i <= N; i++)
	{
		a = max(a, ans[i]);
	}
	cout << a;
}