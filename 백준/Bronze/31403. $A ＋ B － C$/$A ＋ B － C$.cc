#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << "\n";
	string str = to_string(a) + to_string(b);
	cout << stoi(str) - c;
}
