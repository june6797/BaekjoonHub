#include <iostream>
#include <vector>
using namespace std;
int arr[51];
vector<int> v[50];
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
	for (int i = 0; i < 51; i++)
	{
		arr[i] = i;
	}
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		uni(0, num);
	}

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		int a;
		cin >> a;
		v[i].push_back(a);
		if (num > 1) {
			for (int j = 0; j < num - 1; j++)
			{
				int b;
				cin >> b;
				uni(a, b);
				v[i].push_back(b);
			}
		}

	}
	int ans = 0;
	bool flag = true;
	for (int i = 0; i < M; i++)
	{
		flag = true;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (find(v[i][j]) == find(0))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans++;
		}
	}
	cout << ans;
}