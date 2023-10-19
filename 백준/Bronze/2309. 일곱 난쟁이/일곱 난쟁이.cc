#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
int arr[9];
int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		sum += num;
	}
	int a = 0, b = 0;
	bool flag = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j)
			{
				if (sum - arr[i] - arr[j] == 100)
				{
					a = i;
					b = j;
					flag = true;
					break;
				}
			}
		}
		if (flag)
		{
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != a && i != b)
		{
			pq.push(arr[i]);
		}
	}
	for (int i = 0; i < 7; i++)
	{
		cout << pq.top() << "\n";
		pq.pop();
	}
}