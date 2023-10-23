#include <iostream>
#include <deque>
using namespace std;

deque<int> s;

int main() {
	string str;
	int N, K;
	cin >> N >> K >> str;
	for (int i = 0; i < str.size(); i++)
	{
		while (!s.empty() && str[i] - '0' > s.back())
		{
			if (K == 0)
			{
				break;
			}
			s.pop_back();
			K--;
		}
		s.push_back(str[i] - '0');
	}
	while (K != 0)
	{
		s.pop_back();
		K--;
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
}