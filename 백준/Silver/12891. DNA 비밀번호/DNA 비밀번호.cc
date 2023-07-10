#include <iostream>
#include <string>
using namespace std;

int arr[4];
int now[4];
int check;
int ans;
void add(char a);
void del(char d);
int main() {
	int S, P;
	cin >> S >> P;
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			check++;
		}
	}
	for (int i = 0; i < P; i++)
	{
		add(str[i]);
	}
	if (check == 4)
	{
		ans++;
	}

	for (int i = P; i < S; i++)
	{
		add(str[i]);
		del(str[i - P]);
		if (check == 4)
		{
			ans++;
		}
	}
	cout << ans;
}

void add(char a) {
	switch (a)
	{
	case 'A':
		now[0]++;
		if (now[0] == arr[0])
		{
			check++;
		}
		break;
	case 'C':
		now[1]++;
		if (now[1] == arr[1])
		{
			check++;
		}
		break;
	case 'G':
		now[2]++;
		if (now[2] == arr[2])
		{
			check++;
		}
		break;
	case 'T':
		now[3]++;
		if (now[3] == arr[3])
		{
			check++;
		}
		break;
	}

}

void del(char d) {
	switch (d)
	{
	case 'A':
		if (now[0] == arr[0])
		{
			check--;
		}
		now[0]--;
		break;
	case 'C':
		if (now[1] == arr[1])
		{
			check--;
		}
		now[1]--;
		break;
	case 'G':
		if (now[2] == arr[2])
		{
			check--;
		}
		now[2]--;
		break;
	case 'T':
		if (now[3] == arr[3])
		{
			check--;
		}
		now[3]--;
		break;
	}
}