#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	int zn = 0, on = 0;
	bool zflag = false, oflag = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] - '0' == 0)
		{
			if (!zflag)
			{
				zn++;
				zflag = true;
				oflag = false;
			}
		}
		else
		{
			if (!oflag)
			{
				on++;
				zflag = false;
				oflag = true;
			}
		}
	}
	cout << min(zn, on);
}