#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int arr[201][201][201];
vector<int> v;
queue<tuple<int, int, int>> q;

void BFS(int a, int b, int c, int A, int B, int C) {
	arr[a][b][c] = 1;
	q.push({ a, b, c });
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();
		if (x == 0)
		{
			v.push_back(z);
		}
		//A to B
		if (x + y > B)
		{
			if (arr[x + y - B][B][z] == 0)
			{
				q.push({ x + y - B, B, z });
			}
			arr[x + y - B][B][z] = 1;
		}
		else
		{
			if (arr[0][x + y][z] == 0)
			{
				q.push({ 0, x + y, z });
			}
			arr[0][x + y][z] = 1;
		}
		//A to C
		if (x + z > C)
		{
			if (arr[x + z - C][y][z] == 0)
			{
				q.push({ x + z - C, y, z });
			}
			arr[x + z - C][y][z] = 1;
		}
		else
		{
			if (arr[0][y][x + z] == 0)
			{
				q.push({ 0, y, x + z });
			}
			arr[0][y][x + z] = 1;
		}
		//B to A
		if (y + x > A)
		{
			if (arr[A][y + x - A][z] == 0)
			{
				q.push({ A, y + x - A, z });
			}
			arr[A][y + x - A][z] = 1;
		}
		else
		{
			if (arr[y + x][0][z] == 0)
			{
				q.push({ y + x, 0, z });
			}
			arr[y + x][0][z] = 1;
		}
		//B to C
		if (y + z > C)
		{
			if (arr[x][y + z - C][C] == 0)
			{
				q.push({ x, y + z - C, C });
			}
			arr[x][y + z - C][C] = 1;
		}
		else
		{
			if (arr[x][0][y + z] == 0)
			{
				q.push({ x, 0, y + z });
			}
			arr[x][0][y + z] = 1;
		}
		//C to A
		if (z + x > A)
		{
			if (arr[A][y][z + x - A] == 0)
			{
				q.push({ A, y, z + x - A });
			}
			arr[A][y][z + x - A] = 1;
		}
		else
		{
			if (arr[z + x][y][0] == 0)
			{
				q.push({ z + x, y, 0 });
			}
			arr[z + x][y][0] = 1;
		}
		//C to B
		if (z + y > B)
		{
			if (arr[x][B][z + y - B] == 0)
			{
				q.push({ x, B, z + y - B });
			}
			arr[x][B][z + y - B] = 1;
		}
		else
		{
			if (arr[x][z + y][0] == 0)
			{
				q.push({ x, y + z, 0 });
			}
			arr[x][z + y][0] = 1;
		}
	}

}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	BFS(0, 0, c, a, b, c);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}