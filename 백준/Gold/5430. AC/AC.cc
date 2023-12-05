#include <iostream>
#include <string>
#include <deque> //deque stl 공부
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	string ac;
	int n;
	string arrnum;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int err = 0;
		int reverse = 0;
		deque<int> d1;
		cin >> ac;
		cin >> n;
		cin >> arrnum;
		string arrok;


		for (int i = 0; i < arrnum.size(); i++)
		{
			if (isdigit(arrnum[i])) //isdigit 수인지 판단
			{
				arrok += arrnum[i];
			}
			else
			{
				if (arrok != "")
				{
					d1.push_back(stoi(arrok));
					arrok = "";
				}
			}
		}

		for (int i = 0; i < ac.size(); i++)
		{
			if (ac[i] == 'R')
			{
				if (reverse == 0)
				{
					reverse = 1;
				}
				else if (reverse == 1)
				{
					reverse = 0;
				}
			}
			else if (ac[i] == 'D')
			{
				if (d1.size() == 0)
				{
					err = 1;
					break;
				}
				else
				{
					if (reverse == 0)
					{
						d1.pop_front();
					}
					else
					{
						d1.pop_back();
					}
				}
			}
		}

		if (err == 0)
		{

			cout << "[";
			if (!d1.empty())
			{
				if (reverse == 0)
				{
					for (int i = 0; i < d1.size() - 1; i++)
					{
						cout << d1[i] << ",";
					}
					cout << d1.back();
				}
				else
				{
					for (int i = 0; i < d1.size() - 1; i++)
					{
						int l = d1.size() - i - 1;
						cout << d1[l] << ",";
					}
					cout << d1.front();
				}
			}

			cout << "]\n";
		}
		else if (err == 1)
		{
			cout << "error\n";
		}


	}
}