#include <iostream>
using namespace std;
int arr[1001][1001];

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 1; j <= str1.size(); j++)
		{
			if (str2.at(i - 1) == str1.at(j - 1))
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	cout << arr[str2.length()][str1.length()];
}