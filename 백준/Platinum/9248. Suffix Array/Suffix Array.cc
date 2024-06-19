#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, t;
int suffix[500010];
int group[500010];
int newgroup[500010];
int tmp[500010];
int lcp[500010];
//compare 작성
bool compare(int a, int b) {
	if (group[a] == group[b])
	{
		return group[a + t] < group[b + t];
	}
	return group[a] < group[b];
}
//getSuffixArray를 직접 구현해보자
void getSuffixArray(string str) {
	t = 1;
	n = str.size();
	for (int i = 0; i < n; i++)
	{
		group[i] = str[i] - 'a';
		suffix[i] = i;
	}
	//t <= n인지 한번더 확인하기 t < n 은 될수없을까?

	/*cout << "group is\n";
	for (int i = 0; i < n; i++)
	{
		cout << group[i] << " ";
	}
	cout << "\n";

	cout << "suffix is\n";
	for (int i = 0; i < n; i++)
	{
		cout << suffix[i] << " ";
	}
	cout << "\n";*/

	while (t < n)
	{
		group[n] = -1;
		sort(suffix, suffix + n, compare);
		/*cout << "suffix is\n";
		for (int i = 0; i < n; i++)
		{
			cout << suffix[i] << " ";
		}
		cout << "\n";*/
		newgroup[suffix[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compare(suffix[i - 1], suffix[i]))
			{
				newgroup[suffix[i]] = newgroup[suffix[i - 1]] + 1;
			}
			else
			{
				newgroup[suffix[i]] = newgroup[suffix[i - 1]];
			}
		}
		for (int i = 0; i < n; i++)
		{
			group[i] = newgroup[i];
		}
		t *= 2;
		/*cout << "group is\n";
		for (int i = 0; i < n; i++)
		{
			cout << group[i] << " ";
		}
		cout << "\n";*/

	}
}

void LCP(string str) {
	for (int i = 0; i < n; i++) {
		tmp[suffix[i]] = i;
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (tmp[i]) {
			int j = suffix[tmp[i] - 1];
			while (str[j + len] == str[i + len]) {
				len++;
			}
			lcp[tmp[i]] = len;

			//여기서 왜 len > 0일때 len--만 해줘도되는가?
			//현재 인접한 두 접미사의 앞 한글자씩을 빼면
			// 이들의 lcp 값은 최소 len - 1이기때문 -> 경이롭다
			if (len > 0) {
				len--;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	getSuffixArray(str);
	LCP(str);
	for (int i = 0; i < n; i++)
	{
		cout << suffix[i]  + 1 << " ";
	}
	cout << "\nx ";
	for (int i = 1; i < n; i++)
	{
		cout << lcp[i] << " ";
	}
}