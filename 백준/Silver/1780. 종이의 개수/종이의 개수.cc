#include <iostream>
#include <string>
using namespace std;

int arr[2187][2187];
int zero = 0, minusone = 0, plusone = 0;
bool onecolor(int size, int x, int y) {
	if (size == 1)
	{
		int what = arr[x][y];
		switch (what)
		{
		case -1:
			minusone++;
			break;
		case 0:
			zero++;
			break;
		case 1:
			plusone++;
			break;
		default:
			break;
		}
		return true;
	}
	int start = arr[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (start != arr[i][j])
			{
				return false;
			}
		}
	}
	int what = arr[x][y];
	switch (what)
	{
	case -1:
		minusone++;
		break;
	case 0:
		zero++;
		break;
	case 1:
		plusone++;
		break;
	default:
		break;
	}
	return true;
}
void findpaper(int size, int x, int y) {
	if (onecolor(size, x, y))
	{
		return;
	}
	int nsize = size / 3;
	findpaper(nsize, x, y);
	findpaper(nsize, x + nsize, y);
	findpaper(nsize, x + 2 * nsize, y);

	findpaper(nsize, x, y + nsize);
	findpaper(nsize, x + nsize, y + nsize);
	findpaper(nsize, x + 2 * nsize, y + nsize);

	findpaper(nsize, x, y + 2 * nsize);
	findpaper(nsize, x + nsize, y + 2 * nsize);
	findpaper(nsize, x + 2 * nsize, y + 2 * nsize);

	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	findpaper(N, 0, 0);
	cout << minusone << "\n";
	cout << zero << "\n";
	cout << plusone << "\n";
}