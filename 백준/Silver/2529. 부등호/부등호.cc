#include <iostream>
#include <vector>
#include <string>
using namespace std;

char compare[9];
int arr[10];
int pick[10];
bool visit[10];
vector<string> v;
void DFS(int depth, int level) {
	if (depth == level)
	{
		string str = to_string(pick[0]);
		bool make = true;
		for (int i = 0; i < level - 1; i++)
		{
			if (compare[i] == '<')
			{
				if (pick[i] > pick[i + 1])
				{
					make = false;
					break;
				}
				else
				{
					str += to_string(pick[i + 1]);
				}
			}
			else
			{
				if (pick[i] < pick[i + 1])
				{
					make = false;
					break;
				}
				else
				{
					str += to_string(pick[i + 1]);
				}
			}
		}
		if (make)
		{
			v.push_back(str);
		}
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			pick[depth] = i;
			DFS(depth + 1, level);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> compare[i];
	}
	DFS(0, k + 1);
	cout << v[v.size() - 1] << "\n" << v[0];
}