#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int idx, int cnt, vector<char> v,
	int L, int C, string str) {
	cnt++;
	if (cnt == L)
	{
		int num = 0;
		for (int i = 0; i < L; i++)
		{
			char a = str.at(i);
			if (a == 'a' || a == 'e' || a == 'i' || a == 'o'
				|| a == 'u') {
				num++;
			}
		}
		if (num > 0 && L - num >= 2)
		{
			cout << str << "\n";
		}
		return;
	}
	for (int i = idx + 1; i < C; i++) {
		str += v[i];
		DFS(i, cnt, v, L, C, str);
		str.pop_back();
	}
}

int main() {
	int L, C;
	vector <char> v;
	string str = "";
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < C; i++)
	{
		str = v[i];
		DFS(i, 0, v, L, C, str);
	}


}
