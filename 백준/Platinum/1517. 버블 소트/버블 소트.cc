#include <iostream>
#include <vector>
using namespace std;

long long int ans;
int arr[500001];
int sarr[500001];
void merge_sort(int s, int e) {
	if (e - s == 0)
	{
		return;
	}
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);

	int l = s;
	int r = m + 1;
	int k = s;
	while (l <= m && r <= e)
	{
		if (arr[l] > arr[r])
		{
			sarr[k] = arr[r];
			ans += r - k;
			r++;
			k++;
		}
		else
		{
			sarr[k] = arr[l];
			l++;
			k++;
		}
	}
	while (l <= m)
	{
		sarr[k] = arr[l];
		l++;
		k++;
	}
	while (r <= e)
	{
		sarr[k] = arr[r];
		r++;
		k++;
	}
	for (int i = s; i <= e; i++)
	{
		arr[i] = sarr[i];
	}

}

int main() {
	int N;
	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	merge_sort(1, N);
	cout << ans;
}