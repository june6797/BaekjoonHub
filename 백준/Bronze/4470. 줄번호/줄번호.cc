#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		string str;
		getline(cin, str);
		cout << i << ". " << str << "\n";
	}
}