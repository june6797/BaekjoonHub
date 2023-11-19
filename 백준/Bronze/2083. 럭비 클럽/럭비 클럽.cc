#include <iostream>
using namespace std;

int main() {
	string str;
	int a, w;
	cin >> str >> a >> w;
	while (str != "#" || a != 0 || w != 0)
	{
		if (a > 17 || w >= 80)
		{
			cout << str << " Senior" << "\n";
		}
		else
		{
			cout << str << " Junior" << "\n";
		}
		cin >> str >> a >> w;
	}

}