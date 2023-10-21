#include <iostream>
using namespace std;

int main() {
	int N, M, ans = 0, check = 0, l = 0;
	cin >> N >> M;
	string str;
	cin >> str;
	if (str.back() == 'I')
	{
		str += 'I';
	}
	else
	{
		str += 'O';
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'O')
		{
			if (check == 1)
			{
				check = 2;
				l++;
			}
			else if (check == 2) {
				if ((l - 1) / 2 >= N)
				{
					ans += (l - 1) / 2 - N + 1;
				}
				check = 0;
				l = 0;
			}
		}
		else
		{
			if (check == 0 || check == 2)
			{
				check = 1;
				l++;
			}
			else if (check == 1)
			{
				if (l / 2 >= N)
				{
					ans += l / 2 - N + 1;
				}
				check = 1;
				l = 1;
			}
		}
	}
	cout << ans;
}