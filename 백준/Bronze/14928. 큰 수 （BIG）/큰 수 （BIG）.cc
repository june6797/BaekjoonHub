#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        int a = str[i] - '0';
        ans = ((ans * 10) % 20000303 + a) % 20000303;
    }
    cout << ans;
}