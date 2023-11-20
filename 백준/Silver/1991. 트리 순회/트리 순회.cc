#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[26][2];

void preOrder(int x) {
	if (x == -1)
	{
		return;
	}
	cout << static_cast<char>(x + 'A');
	preOrder(arr[x][0]);
	preOrder(arr[x][1]);

}
void inOrder(int x) {
	if (x == -1)
	{
		return;
	}
	inOrder(arr[x][0]);
	cout << static_cast<char>(x + 'A');
	inOrder(arr[x][1]);

}
void postOrder(int x) {
	if (x == -1)
	{
		return;
	}
	postOrder(arr[x][0]);
	postOrder(arr[x][1]);
	cout << static_cast<char>(x + 'A');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if (l == '.')
		{
			arr[p - 'A'][0] = -1;
		}
		else
		{
			arr[p - 'A'][0] = l - 'A';
		}
		if (r == '.')
		{
			arr[p - 'A'][1] = -1;
		}
		else
		{
			arr[p - 'A'][1] = r - 'A';
		}
	}
	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
}