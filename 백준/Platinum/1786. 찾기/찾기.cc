#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> tarr(1000001);
vector<int> parr(1000001);
queue<int>q;
int main() {
	int ans = 0;
	string t, p;
	getline(cin, t);
	getline(cin, p);
	for (int i = 1, j = 0; i < p.size(); i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = parr[j - 1];
		}
		if (p[i] == p[j])
		{
			j++;
			parr[i] = j;
		}
	}
	for (int i = 0, j = 0; i < t.size(); i++)
	{
		while (j > 0 && t[i] != p[j])
		{
			j = parr[j - 1];
		}
		if (t[i] == p[j])
		{
			j++;
			if (j == p.size())
			{
				ans++;
				q.push(i - p.size() + 2);
				j = parr[j - 1];
			}
		}
	}
	cout << ans << "\n";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}