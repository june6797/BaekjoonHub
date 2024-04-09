#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;
 
int N;
int arr[2001];
vector<int> v, mi;
int gcd(int n, int m) {
    if (m == 0)
    {
        return n;
    }
    return gcd(m, n % m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin >> C;
    while (C--)
    {
        cin >> N;
        v.clear();
        mi.clear();
        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < N; i++)
        {
            if (v[i] - v[i - 1] > 0)
            {
                mi.push_back({ v[i] - v[i - 1] });
            }
        }
        int ans = 0;
        if (mi.size() > 0)
        {
            ans = mi[0];
            for (int i = 1; i < mi.size(); i++)
            {
                ans = gcd(ans, mi[i]);
            }
        }
        if (ans == 0)
        {
            cout << "INFINITY\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    
}