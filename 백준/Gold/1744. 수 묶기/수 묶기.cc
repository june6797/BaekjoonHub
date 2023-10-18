#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> ppq;
priority_queue<int, vector<int>, greater<int>> mpq;
int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num > 1)
		{
			ppq.push(num);
		}
		else if (num == 1)
		{
			ans++;
		}
		else
		{
			mpq.push(num);
		}
	}
	while (ppq.size() > 1)
	{
		int a = ppq.top();
		ppq.pop();
		int b = ppq.top();
		ppq.pop();
		ans += a * b;
	}
	while (mpq.size() > 1)
	{
		int a = mpq.top();
		mpq.pop();
		int b = mpq.top();
		mpq.pop();
		ans += a * b;
	}
	if (!ppq.empty())
	{
		ans += ppq.top();
	}
	if (!mpq.empty())
	{
		ans += mpq.top();
	}
	cout << ans;
}