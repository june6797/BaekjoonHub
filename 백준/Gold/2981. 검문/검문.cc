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
vector<int> v, mi, kk;
int gcd(int n, int m) {
    if (m == 0)
    {
        return n;
    }
    return gcd(m, n % m);
}
void findfac(int start) {
    for (int i = 1; i * i <= start; i++)
    {
        if (start % i == 0)
        {
            kk.push_back(i);
            if (start / i != i)
            {
                kk.push_back(start / i);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        cin >> N;
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
        findfac(ans);
        sort(kk.begin(), kk.end());
        for (int i = 1; i < kk.size(); i++)
        {
            cout << kk[i] << " ";
        }
}