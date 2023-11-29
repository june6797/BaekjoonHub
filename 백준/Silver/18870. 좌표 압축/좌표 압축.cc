#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, int> m;
int arr[1000001];
vector<int> v;
int main()
{

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (m.find(arr[i]) == m.end())
		{
			v.push_back(arr[i]);
			m[arr[i]] = 0;
		}
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		m[v[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < N; i++)
	{
		cout << m[arr[i]] << " ";
	}
}