#include <iostream>
#include <vector>
using namespace std;

int arr[5000001];
int main() {
	vector <int> v;
	int N, ans;
	cin >> N;
	for (int i = 2; i*i <= N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * i; j <= N; j += i) {
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			v.push_back(i);
		}
	}
	int start = 0;
	int end = v.size() - 1;
	int Q = 20;
	for (int i = 0; i < Q; i++)
	{
		int mid = (start + end) / 2;
		int check = v[mid];
		cout << "? " << check << "\n" << flush;
		
		int what;
		cin >> what;
		if (start == end)
		{
			if (what == 0) {
				ans = check;
			}
			break;
		}
		else
		{
			if (what == 1)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
				ans = check;
			}
		}
	}
	cout << "! " << ans << "\n" << flush;
}