#include <iostream>
using namespace std;

int num[13];
bool pick[13];
void DFS(int cnt, int data, int level, int k) {
	if (cnt == level)
	{
		for (int i = 0; i < k; i++)
		{
			if (pick[i] == true)
			{
				cout << num[i] << " ";
			}
		}
		cout << "\n";
		return;
	}
	for (int i = data; i < k; i++)
	{
		pick[i] = true;
		DFS(cnt + 1, i + 1, level, k);
		pick[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		for (int i = 0; i < k; i++)
		{
			cin >> num[i];
		}
		DFS(0, 0, 6, k);
		cout << "\n";
	}
}