#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int C;
	int N;
	int S;
    
	cin >> C;
	for (int i = 0; i < C; i++)
	{
        double sum = 0;
	    double av = 0;
        double per = 0;
		cin >> N;
		double* array = new double[N];
		for (int i = 0; i < N; i++)
		{
			cin >> S;
			array[i] = S;
			sum = sum + S;
		}

		av = double(sum) / N;

		for (int j = 0; j < N; j++)
		{
			if (array[j] > av)
			{
				per = per + 1;
			}
		}

		double answer = (per / N)*100000;
		double ans = round(answer);
		cout.precision(3);
		cout << fixed;
		cout << ans/1000 << "%" << "\n";
        delete []array;
	}


}