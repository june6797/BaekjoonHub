#include <iostream>
#include <math.h>
using namespace std;

void fixHeap(int arr[], int N, int i) {
	int K = i;
	int left = i * 2;
	int right = i * 2 + 1;

	if (left < N + 1 && arr[left] > arr[K])
	{
		K = left;
	}

	if (right < N + 1 && arr[right] > arr[K])
	{
		K = right;
	}

	if (K != i)
	{
		int temp = arr[i];
		arr[i] = arr[K];
		arr[K] = temp;
		fixHeap(arr, N, K);
	}
}

void constructHeap(int arr[], int N) {
	for (int i = N / 2; i >= 1; i--)
	{
		fixHeap(arr, N, i);
	}
}

void bubbleUpHeap(int arr[], int root, int K, int vacant, int &time) {
	if (vacant == root)
	{
		arr[vacant] = K;
		time++;
	}
	else
	{
		int parent = vacant / 2;
		if (K <= arr[parent])
		{
			arr[vacant] = K;
		}
		else
		{
			time++;
			arr[vacant] = arr[parent];
			bubbleUpHeap(arr, root, K, parent, time);
		}
	}
};

int promote(int arr[], int hStop, int vacant, int h, int N, int& time) {
	int vacStop;
	if (h <= hStop)
	{
		vacStop = vacant;
	}
	else if (vacant * 2 + 1 < N && arr[vacant * 2] <= arr[vacant * 2 + 1])
	{
		arr[vacant] = arr[vacant * 2 + 1];
		vacStop = promote(arr, hStop, vacant * 2 + 1, h - 1, N, time);
		time++;
	}
	else
	{
		if (vacant * 2 + 1 < N) {
			time++;
		}
		arr[vacant] = arr[vacant * 2];
		vacStop = promote(arr, hStop, vacant * 2, h - 1, N, time);

	}
	return vacStop;
};

void fixHeapFast(int arr[], int N, int K, int vacant, int h, int& time) {
	if (h <= 1)
	{
		if (vacant * 2 + 1 < N && arr[vacant * 2] < arr[vacant * 2 + 1])
		{
			if (arr[vacant * 2 + 1] > K)
			{
				int temp = arr[vacant * 2 + 1];
				arr[vacant * 2 + 1] = K;
				arr[vacant] = temp;
				time++;
			}
			else
			{
				arr[vacant] = K;
			}
		}
		else if (vacant * 2 + 1 < N && arr[vacant * 2] > arr[vacant * 2 + 1])
		{
			if (arr[vacant * 2] > K)
			{
				int temp = arr[vacant * 2];
				arr[vacant * 2] = K;
				arr[vacant] = temp;
				time++;
			}
			else
			{
				arr[vacant] = K;
			}
		}
		else
		{
			arr[vacant] = K;
		}
	}
	else
	{
		int hStop = h / 2;
		int vacStop = promote(arr, hStop, vacant, h, N, time);
		int vacParent = vacStop / 2;
		if (arr[vacParent] <= K)
		{
			arr[vacStop] = arr[vacParent];
			bubbleUpHeap(arr, vacant, K, vacParent, time);
		}
		else
		{
			fixHeapFast(arr, N, K, vacStop, hStop, time);
		}
	}
};

void deleteMax(int arr[], int N, int& time) {
	int h = log2(N + 1);
	int K = arr[N];
	int vacant = 1;
	arr[N] = arr[1];
	arr[1] = 0;
	if (N != 1)
	{
		time++;
	}
	fixHeapFast(arr, N, K, vacant, h, time);
};

int main() {
	int T;
	int N;
	int S;
	//cin >> T;
	//for (int i = 0; i < T; i++)
	//{
		int time = 0;
		cin >> N;
		int* arr = new int[N + 1];
		for (int i = 0; i < N; i++)
		{
			cin >> S;
			arr[i + 1] = S;
		}
		constructHeap(arr, N);

		////for (int i = 0; i < N; i++)
		//{
		//	cout << arr[i + 1] << " ";
		//}
		//cout << "\n";
		for (int i = N; i >= 1; i--)
		{
			deleteMax(arr, i, time);
		}


		for (int i = 0; i < N; i++)
		{
			cout << arr[i + 1] << "\n";
		}

		/*for (int i = 0; i < N; i++)
		{
			cout << arr[i + 1] << " ";
		}
		cout << time << "\n";*/
		delete[]arr;
	//}

}