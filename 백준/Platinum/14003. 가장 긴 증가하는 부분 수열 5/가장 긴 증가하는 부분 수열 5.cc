#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int num;
	cin >> N;
	int* arr = new int[N + 1];
	int* idx = new int[N + 1];
	arr[0] = -1000000001;
	vector<int> v1;
	vector<int> v2;
	v1.push_back(-1000000001);
	for (int i = 1; i < N + 1; i++)
	{
		cin >> num;
		arr[i] = num;
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (arr[i] > v1.back())
		{
			v1.push_back(arr[i]);
			idx[i] = v1.size() - 1;
		}
		else
		{
			int start = 0;
			int end = v1.size() - 1;
			int key = arr[i];
			while (start <= end)
			{
				int mid = (start + end) / 2;
				if (key <= v1[mid])
				{
					end = mid - 1;
				}
				else if (key > v1[mid])
				{
					start = mid + 1;
				}
			}
			idx[i] = start;
			v1[start] = key;
		}

	}
	cout << v1.size() - 1 << "\n";
	int ans = v1.size() - 1;
	for (int i = N; i > 0; i--)
	{
		if (idx[i] == ans)
		{
			v2.push_back(arr[i]);
			ans--;
		}
	}
	for (int i = v2.size() - 1; i >= 0; i--)
	{
		cout << v2[i] << " ";
	}
	delete[] arr;

}