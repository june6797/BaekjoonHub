#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[10000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 2; i < 10000000; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i < 10000000; i++)
	{
		if (arr[i])
		{
			for (int j = i * 2; j < 10000000; j = j + i)
			{
				arr[j] = 0;
			}
		}
		if (arr[i]) {
			string str = to_string(i);
			for (int j = 0; j < str.size() / 2; j++)
			{
				if (str[j] != str[str.size() - j - 1])
				{
					arr[i] = 0;
					break;
				}
			}
		}
	}
	while (arr[N] == 0)
	{
		N++;
	}
	cout << N;
}