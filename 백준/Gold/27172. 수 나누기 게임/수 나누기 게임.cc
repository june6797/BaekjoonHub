#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

vector<int> v;
vector<int> v1;
long long int arr[1000001];
bool check[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		v1.push_back(num);
		check[num] = true;
	}
	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i];
		for (int j = 1; j * j <= a; j++)
		{
			if (a % j == 0)
			{
				int small = j;
				int big = a / j;
				if (small == big)
				{
					if (check[small])
					{
						arr[small]++;
						arr[a]--;
					}
				}
				else
				{
					if (check[small])
					{
						arr[small]++;
						arr[a]--;
					}
					if (check[big])
					{
						arr[big]++;
						arr[a]--;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[v1[i]] << " ";
	}
}
