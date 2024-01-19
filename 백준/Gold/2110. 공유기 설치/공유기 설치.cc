#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int C;
	int X;
	vector<int> v1;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		v1.push_back(X);
	}
	sort(v1.begin(), v1.end());

	int start = 0; 
	int end = v1.back();
	int mid = (v1[N - 1] - v1[0]) / 2; //X1과 Xn 좌표의 거리의 반부터 시작
	int num = 1;

	int first = 0;
	int go = 0;

	while (start <= end)
	{
		while (go != N - 1)
		{
			for (int i = 1; i < N; i++)
			{
				if (v1[i] - v1[first] >= mid)
				{
					num++;
					first = i;
				}
				go++;
			}
		}
		go = 0;
		first = 0;
		if (num < C)
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (num >= C)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		num = 1;
	}
	cout << mid;
}
