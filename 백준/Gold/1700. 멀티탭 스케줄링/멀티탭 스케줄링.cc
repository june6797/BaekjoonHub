#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int arr[101];
bool check[101];
int plug[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++)
	{

		/*for (int p = 0; p < cnt; p++)
		{
			cout << plug[p] << " ";
		}
		cout << "\n";*/
		int temp = arr[i];
		if (check[temp])
		{
			continue;
		}

		if (cnt < n)
		{
			check[temp] = 1;
			plug[cnt] = temp;
			cnt++;
			continue;
		}
		int idx = i;
		bool flag = true;
		for (int j = 0; j < cnt; j++)
		{
			int num = plug[j];
			int tempidx = i;
			int tempidx2 = k + 1;
			for (int l = i + 1; l < k; l++)
			{
				if (arr[l] == num)
				{
					tempidx = l;
					break;
				}
			}
			if (tempidx == i)
			{
				plug[j] = arr[i];
				check[num] = 0;
				check[arr[i]] = 1;
				ans++;
				flag = false;
				break;
			}
			else
			{
				idx = max(idx, tempidx);
			}
		}
		if (flag)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[idx] == plug[j])
				{
					plug[j] = arr[i];
					break;
				}
			}
			check[arr[idx]] = 0;
			check[arr[i]] = 1;
			ans++;
		}
	}
	cout << ans;
}