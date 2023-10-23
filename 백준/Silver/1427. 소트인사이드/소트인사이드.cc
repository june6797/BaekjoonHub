#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;
int main() {
	string str;
	cin >> str;
	for (size_t i = 0; i < str.size(); i++)
	{
		pq.push(str[i] - '0');
	}
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}