#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int mm = 0;
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (mm < A[i])
		{
			mm = A[i];
		}
	}
	int M;
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
		if (mm < B[i])
		{
			mm = B[i];
		}
	}
	vector<int>::iterator it_a = A.begin(), it_b = B.begin();
	vector<int> ans;

	for (int i = mm; i >= 1; --i)
	{
		while (true)
		{
			vector<int>::iterator nxt_a = find(it_a, A.end(), i);
			vector<int>::iterator nxt_b = find(it_b, B.end(), i);
			if (nxt_a == A.end() || nxt_b == B.end())
				break;

			ans.push_back(i);
			it_a = next(nxt_a);
			it_b = next(nxt_b);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}