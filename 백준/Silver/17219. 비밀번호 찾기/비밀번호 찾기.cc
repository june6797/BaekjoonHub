#include <iostream>
#include <map>
using namespace std;

map<string, string> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		m[str1] = str2;
	}
	for (int j = 0; j < M; j++)
	{
		string str1;
		cin >> str1;
		cout << m[str1] << "\n";
	}
}