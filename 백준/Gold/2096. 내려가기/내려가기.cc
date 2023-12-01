#include <iostream>
using namespace std;

int ans1[3];
int temp1[3];
int ans2[3];
int temp2[3];
int main() {
	for (int i = 0; i < 3; i++)
	{
		ans2[i] = 1234567890;
	}
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ans1[0] = max(temp1[0] + a, temp1[1] + a);

		ans1[1] = max(temp1[0] + b, temp1[1] + b);
		ans1[1] = max(ans1[1], temp1[2] + b);

		ans1[2] = max(temp1[1] + c, temp1[2] + c);

		ans2[0] = min(temp2[0] + a, temp2[1] + a);

		ans2[1] = min(temp2[0] + b, temp2[1] + b);
		ans2[1] = min(ans2[1], temp2[2] + b);

		ans2[2] = min(temp2[1] + c, temp2[2] + c);
		for (int j = 0; j < 3; j++)
		{
			temp1[j] = ans1[j];
			temp2[j] = ans2[j];
		}
	}
	int ma = 0;
	int mi = 1234567890;
	for (int i = 0; i < 3; i++)
	{
		if (ma < ans1[i])
		{
			ma = ans1[i];
		}
		if (mi > ans2[i])
		{
			mi = ans2[i];
		}
	}
	cout << ma << " " << mi;
}