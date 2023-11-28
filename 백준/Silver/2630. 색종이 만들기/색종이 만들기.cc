#include <iostream>
using namespace std;

int arr[128][128];
int answ, ansb;
void findW(int x, int y, int N) {
	if (N == 1)
	{
		if (arr[x][y] == 0)
		{
			answ++;
		}
		return;
	}
	else
	{
		bool flag = true;
		for (int i = x; i < x + N; i++)
		{
			for (int j = y; j < y + N; j++)
			{
				if (arr[i][j] == 1)
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
		if (flag)
		{
			answ++;
		}
		else
		{
			findW(x, y, N / 2);
			findW(x, y + N / 2, N / 2);
			findW(x + N / 2, y, N / 2);
			findW(x + N / 2, y + N / 2, N / 2);
		}
	}

}

void findB(int x, int y, int N) {
	if (N == 1)
	{
		if (arr[x][y] == 1)
		{
			ansb++;
		}
		return;
	}
	else
	{
		bool flag = true;
		for (int i = x; i < x + N; i++)
		{
			for (int j = y; j < y + N; j++)
			{
				if (arr[i][j] == 0)
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
		if (flag)
		{
			ansb++;
		}
		else
		{
			findB(x, y, N / 2);
			findB(x, y + N / 2, N / 2);
			findB(x + N / 2, y, N / 2);
			findB(x + N / 2, y + N / 2, N / 2);
		}
	}

}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	findW(0, 0, N);
	cout << answ << "\n";
	findB(0, 0, N);
	cout << ansb << "\n";
}