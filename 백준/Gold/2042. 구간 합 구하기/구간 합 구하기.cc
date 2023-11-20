#include <iostream>
#include <cmath>
using namespace std;

long long int arr[5000001];

void change(int idx, long long int c) {
	long long int diff = c - arr[idx];
	while (idx > 0)
	{
		arr[idx] += diff;
		idx /= 2;
	}

}
void calsum(int start, int end) {
	long long sum = 0;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			sum += arr[start];
			start++;
		}
		if (end % 2 == 0)
		{
			sum += arr[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	cout << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	int height = ceil(log2(N));
	int treesize = pow(2, height + 1);
	int startindex = treesize / 2;
	for (int i = startindex; i < startindex + N; i++)
	{
		cin >> arr[i];
	}
	int temp = treesize - 1;
	while (temp != 1)
	{
		arr[temp / 2] += arr[temp];
		temp--;
	}
	for (int i = 0; i < M + K; i++)
	{
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			change(startindex + b - 1, c);
		}
		else if (a == 2)
		{
			calsum(startindex + b - 1, startindex + c - 1);
		}
	}
}