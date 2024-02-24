#include <iostream>
using namespace std;

char a[3] = { 'A','B','C' };
char b[4] = { 'B','A','B','C' };
char c[6] = { 'C','C','A','A','B','B' };

int cnt[3] = { 0 };

int main() {

	int n, ans = 0;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		if (a[i % 3] == str[i]) cnt[0]++;
		if (b[i % 4] == str[i]) cnt[1]++;
		if (c[i % 6] == str[i]) cnt[2]++;
	}
	for (int i = 0; i < 3; i++) {
		if (ans < cnt[i]) {
			ans = cnt[i];
		}
	}
	cout << ans << "\n";
	if (cnt[0] == ans) cout << "Adrian" << "\n";
	if (cnt[1] == ans) cout << "Bruno" << "\n";
	if (cnt[2] == ans) cout << "Goran" << "\n";
}