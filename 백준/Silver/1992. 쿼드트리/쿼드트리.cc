#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

bool onecolor(int size, int x, int y) {
	if (size == 1)
	{
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
	return true;
}
string makecolor(int size, int x, int y) {
	if (onecolor(size, x, y))
	{
		return to_string(arr[x][y]);
	}
	int nsize = size / 2;
	string ul = makecolor(nsize, x, y);
	string ur = makecolor(nsize, x, y + nsize);
	string dl = makecolor(nsize, x + nsize, y);
	string dr = makecolor(nsize, x + nsize, y + nsize);

	return "(" + ul + ur + dl + dr + ")";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	cout << makecolor(N, 0, 0);
}