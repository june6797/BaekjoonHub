#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] <= 'Z')
			{
				cout << static_cast<char>(str[j] + 32);
			}
			else
			{
				cout << str[j];
			}
		}
		cout << "\n";
	}
}