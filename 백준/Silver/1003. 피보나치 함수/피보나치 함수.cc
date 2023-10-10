#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    int arr0[41], arr1[41];
    arr0[0] = 1;
    arr0[1] = 0;
    arr1[0] = 0;
    arr1[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        arr0[i] = arr0[i - 1] + arr0[i - 2];
        arr1[i] = arr1[i - 1] + arr1[i - 2];
    }
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << arr0[n] << " " << arr1[n] << "\n";
    }
}