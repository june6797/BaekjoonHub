#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str.size() >= 6 && str.size() <= 9) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}