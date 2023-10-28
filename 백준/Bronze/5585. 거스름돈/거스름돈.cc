#include <iostream>
using namespace std;
int main() {
    int m, ans = 0;
    cin >> m;
    m = 1000 - m;
    ans += m / 500;
    m = m % 500;
    ans += m / 100;
    m = m % 100;
    ans += m / 50;
    m = m % 50;
    ans += m / 10;
    m = m % 10;
    ans += m / 5;
    m = m % 5;
    ans += m;
    cout << ans;
    
}