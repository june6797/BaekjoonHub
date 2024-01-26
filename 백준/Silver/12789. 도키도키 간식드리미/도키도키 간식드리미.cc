#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int cnt = 1;
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num != cnt)
		{
			while (!s.empty() && cnt == s.top())
			{
				s.pop();
				cnt++;
			}
			if (num != cnt)
			{
				if (!s.empty() && s.top() < num)
				{
					flag = false;
				}
				if (flag)
				{
					s.push(num);
				}
			}
			else
			{
				cnt++;
			}
		}
		else
		{
			cnt++;
		}
	}

	if (flag)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Sad";
	}
}