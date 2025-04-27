#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += 32;
        }
        else if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] -= 32;
        }
    }
    cout << str;
}