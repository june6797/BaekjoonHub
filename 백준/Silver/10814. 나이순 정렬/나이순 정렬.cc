#include <iostream>
#include <vector>
using namespace std;

vector<string> v[100001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		string str;
		cin >> num >> str;
		v[num].push_back(str);
	}
	for (int i = 0; i < 100001; i++)
	{
		if (v[i].size())
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << i << " " << v[i][j] << "\n";
			}
		}
	}
}