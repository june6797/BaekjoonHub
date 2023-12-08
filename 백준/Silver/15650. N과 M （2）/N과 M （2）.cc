#include <iostream>
using namespace std;
void DFS(int start, int n, int d, int m, string str) {
	if (d == m)
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start + 1; i <= n - (m - d) + 1; i++)
	{
		str += i + '0';
		DFS(i, n, d + 1, m, str);
		str.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str = "";
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - m + 1; i++)
	{
		str += i + '0';
		DFS(i, n, 1, m, str);
		str.pop_back();
	}

}