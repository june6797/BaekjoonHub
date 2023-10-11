#include <iostream>
#include <string>
#include <map>
using namespace std;

string arr[100001];
map <string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string str;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		m.insert({ str, i });
		arr[i] = str;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (str.at(0) >= '0' && str.at(0) <= '9')
		{
			cout << arr[stoi(str)] << "\n";
		}
		else
		{
			cout << m[str] << "\n";
		}
	}
}