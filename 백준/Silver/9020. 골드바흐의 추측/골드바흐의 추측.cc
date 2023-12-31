#include <iostream>
#include <unordered_map>
using namespace std;

bool p[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	p[1] = true;
	for (int i = 2; i < 10001; i++)
	{
		if (p[i] == false)
		{
			for (int j = i * 2; j < 10001; j = j + i)
			{
				p[j] = true;
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		int s, b;
		for (int j = n / 2; j > 1; j--)
		{
			if (p[j] == false && p[n - j] == false)
			{
				s = j;
				b = n - j;
				break;
			}
		}
		if (s > b)
		{
			cout << b << " " << s << "\n";
		}
		else
		{
			cout << s << " " << b << "\n";
		}
	}
}