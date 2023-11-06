#include <iostream>
using namespace std;
int arr[1000001];

int find(int a) {
	if (a == arr[a])
	{
		return a;
	}
	else
	{
		return arr[a] = find(arr[a]);
	}
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
	{
		arr[b] = a;
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int num, a, b;
		cin >> num >> a >> b;
		if (num)
		{
			a = find(a);
			b = find(b);
			if (a == b)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			unionfunc(a, b);
		}
	}
}