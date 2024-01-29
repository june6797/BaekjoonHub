#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	sort(v.begin(), v.end());
	cout << sum / 5 << "\n" << v[2];
}