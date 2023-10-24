#include <iostream>
#include <algorithm>
using namespace std;
int bs(int start, int end, int key, int* arr) {
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == key)
		{
			return 1;
		}
		else if (arr[mid] > key)
		{
			end = mid - 1;
		}
		else if (arr[mid] < key)

		{
			start = mid + 1;
		}

	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	int M;
	int X;
	cin >> N;
	int arr[100000];
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		arr[i] = X;
	}

	sort(arr, arr + N); //sort 알고리즘 정렬 AVL트리로도 만들어보기


	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X;
		cout << bs(0, N - 1, X, arr) << "\n";

	}

}