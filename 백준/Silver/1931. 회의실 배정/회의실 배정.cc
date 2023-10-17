#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
	int start;
	int end;
	Node(int X, int Y) {
		this->start = X;
		this->end = Y;
	}
};
bool compare(const Node& a, const Node& b) {
	if (a.end == b.end)
	{
		return a.start < b.start;
	}
	else
	{
		return a.end < b.end;
	}
}

int main() {
	int N;
	int head;
	int tail;
	int ans = 0;
	cin >> N;
	vector<Node> s1;
	for (int i = 0; i < N; i++)
	{
		cin >> head >> tail;

		s1.push_back(Node(head, tail));
	}

	sort(s1.begin(), s1.end(), compare);

	int idx = 0;
	int mid = 0;
	while (idx < N)
	{
		if (mid <= s1[idx].start)
		{
			mid = s1[idx].end;
			ans++;
		}
		idx++;
	}
	cout << ans;

}