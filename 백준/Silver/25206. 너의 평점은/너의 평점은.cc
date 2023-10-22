#include <iostream>
#include <string>
using namespace std;
int main() {
	double scoresum = 0;
	double realscore = 0;
	for (int i = 0; i < 20; i++) {
		string str;
		double score;
		string a;
		cin >> str >> score >> a;
		if (a != "P") {
			scoresum += score;
		}
		if (a == "A+") {
			realscore += score * 4.5;
		}
		else if (a == "A0")
		{
			realscore += score * 4.0;
		}
		else if (a == "B+")
		{
			realscore += score * 3.5;
		}
		else if (a == "B0")
		{
			realscore += score * 3.0;
		}
		else if (a == "C+")
		{
			realscore += score * 2.5;
		}
		else if (a == "C0")
		{
			realscore += score * 2.0;
		}
		else if (a == "D+")
		{
			realscore += score * 1.5;
		}
		else if (a == "D0")
		{
			realscore += score * 1.0;
		}
		else if (a == "F")
		{
			realscore += score * 0;
		}
	}
	cout << realscore / scoresum;
}