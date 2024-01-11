#include <iostream>
using namespace std;

int inorder[100001];
int postorder[100001];
void preorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe)
	{
		return;
	}
	int root = postorder[pe];
	int idx = -1;
	for (int i = 1; i <= ie; i++)
	{
		if (inorder[i] == root)
		{
			idx = i;
			break;
		}
	}

	cout << root << " ";
	preorder(is, ie - 1, ps, ps + idx - is - 1);
	preorder(idx + 1, ie, ps + idx - is, pe - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> inorder[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> postorder[i];
	}
	preorder(1, n, 1, n);
}