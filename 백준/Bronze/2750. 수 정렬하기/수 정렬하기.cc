#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int X;
	cin >> N;
	vector<int> v1;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		v1.push_back(X);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < N; i++)
	{
		cout << v1[i] << "\n";
	}
}