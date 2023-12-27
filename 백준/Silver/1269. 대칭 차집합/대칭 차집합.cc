#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		int num;
		cin >> num;
		m.insert({ num, 0 });
	}
	for (int i = 0; i < b; i++)
	{
		int num;
		cin >> num;
		if (m.find(num) != m.end())
		{
			cnt++;
		}
	}
	cout << a + b - 2 * cnt;
}