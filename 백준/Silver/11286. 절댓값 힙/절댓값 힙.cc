#include <iostream>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator() (int op1, int op2) {
		if (abs(op1) == abs(op2))
		{
			return op1 > op2;
		}
		else
		{
			return abs(op1) > abs(op2);
		}
	}
};

int main() {
	priority_queue<int, vector<int>, cmp> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			pq.push(num);
		}
	}
}