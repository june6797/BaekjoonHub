#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, v[i] * (i + 1));
	}
	cout << ans;
}