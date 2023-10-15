#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node
{
public:
	Node* child[10];
	int check = 0;
	Node() {
		for (int i = 0; i < 10; i++)
		{
			child[i] = nullptr;
		}
		check = 0;
	}

};

void insert(Node& node, string str, int idx, int& ans) {
	if (idx == str.length())
	{
		node.check = 1;
		return;
	}

	if (node.check == 1)
	{
		ans = 1;
	}
	int num = str.at(idx) - 48;
	if (node.child[num] == nullptr)
	{
		node.child[num] = new Node();
	}
	insert(*node.child[num], str, idx + 1, ans);
}


int main() {

	int T;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		Node root;
		vector <string> v;
		int n;
		cin >> n;
		int ans = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		/*for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				str = v[i][j];

				insert(root, str, 0, ans);
				if (ans == 1)
				{
					break;
				}
			}
		}*/
		for (int i = 0; i < v.size(); i++)
		{
			str = v[i];
			insert(root, str, 0, ans);
		}

		if (ans == 1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}
