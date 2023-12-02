#include <iostream>
using namespace std;

char arr[3072][6144];
void draw(int x, int y, int N) {
	if (N == 3)
	{
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		arr[x + 2][y - 2] = '*';
		arr[x + 2][y - 1] = '*';
		arr[x + 2][y - 0] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		return;
	}
	draw(x, y, N / 2);
	draw(x + N / 2, y - N / 2, N / 2);
	draw(x + N / 2, y + N / 2, N / 2);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2 - 1; j++)
		{
			arr[i][j] = ' ';
		}
	}
	draw(0, N - 1, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2 - 1; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
}