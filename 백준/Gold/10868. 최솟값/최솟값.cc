#include <iostream>
#include <cmath>
using namespace std;

int tree[500001];

int getMin(int a, int b) {
	int ans = 1234567890;
	while (a <= b) {
		if (a % 2 == 1)
		{
			ans = min(ans, tree[a]);
			a++;
		}
		if (b % 2 == 0)
		{
			ans = min(ans, tree[b]);
			b--;
		}
		a /= 2;
		b /= 2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int height = ceil(log2(N));
	int treesize = pow(2, height + 1);
	int start = treesize / 2;

	for (int i = 1; i < treesize; i++)
	{
		tree[i] = 1234567890;
	}

	for (int i = start; i < start + N; i++)
	{
		int num;
		cin >> num;
		tree[i] = num;
	}


	int temp = treesize - 1;
	while (temp != 1)
	{
		if (tree[temp / 2] > tree[temp])
		{
			tree[temp / 2] = tree[temp];
		}
		temp--;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a += start - 1;
		b += start - 1;
		cout << getMin(a, b) << "\n";
	}

}