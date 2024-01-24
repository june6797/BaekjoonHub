#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		cout << char(str[i] - 32);
	}
}