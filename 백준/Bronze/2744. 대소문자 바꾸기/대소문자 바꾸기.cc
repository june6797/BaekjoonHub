#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			cout << static_cast<char>(str[i] - 'a' + 'A');
		}
		else
		{
			cout << static_cast<char>(str[i] - 'A' + 'a');
		}
	}
}