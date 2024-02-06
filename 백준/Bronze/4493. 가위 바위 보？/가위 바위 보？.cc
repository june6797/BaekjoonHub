#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int a = 0, b = 0;
		for (int j = 0; j < n; j++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			if (str1 == "R")
			{
				if (str2 == "R")
				{

				}
				else if (str2 == "S")
				{
					a++;
				}
				else
				{
					b++;
				}
			}
			else if (str1 == "S")
			{
				if (str2 == "R")
				{
					b++;
				}
				else if (str2 == "S")
				{

				}
				else
				{
					a++;
				}
			}
			else
			{
				if (str2 == "R")
				{
					a++;
				}
				else if (str2 == "S")
				{
					b++;
				}
				else
				{

				}
			}
		}
		if (a > b)
		{
			cout << "Player 1\n";
		}
		else if (a < b)
		{
			cout << "Player 2\n";
		}
		else
		{
			cout << "TIE\n";
		}
	}
}