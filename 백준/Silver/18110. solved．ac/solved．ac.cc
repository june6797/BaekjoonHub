#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;
int main() {
	double n;
	cin >> n;
	int c = floor(n * 15 / 100 + 0.5);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	double sumscore = 0;
	for (int i = 0; i < n - 2 * c; i++)
	{
		sumscore += v[c + i];
	}
	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		cout << floor(sumscore / (n - 2 * c) + 0.5);
	}
}