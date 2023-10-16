#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, ans = 0;
	cin >> N;
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < N; i++)
	{
		ans += v1[i] * v2[N - 1 - i];
	}
	cout << ans;
}