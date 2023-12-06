#include <iostream>
using namespace std;
long long int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	arr[1] = 0;
	arr[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]) % 1000000000;
	}
	cout << arr[N];
}