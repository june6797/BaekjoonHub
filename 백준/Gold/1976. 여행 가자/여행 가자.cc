#include <iostream>
using namespace std;
int arr[201];

int find(int a) {
	if (a == arr[a])
	{
		return a;
	}
	else
	{
		return find(arr[a]);
	}
}

void uni(int a, int b) {
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
	for (int i = 1; i <= 200; i++)
	{
		arr[i] = i;
	}
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			if (num)
			{
				uni(i, j);
			}
		}
	}
	bool flag = false;
	int f, s;
	cin >> f;
	f = find(f);
	for (int i = 0; i < M - 1; i++)
	{
		cin >> s;
		s = find(s);
		if (s != f)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}