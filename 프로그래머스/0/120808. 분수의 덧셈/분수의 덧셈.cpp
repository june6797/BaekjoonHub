#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}
vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    int a = numer1 * denom2;
    int b = numer2 * denom1;
    int u = denom1 * denom2;
    int ff = gcd(a + b, u);
    answer[0] = (a + b) / ff;
    answer[1] = u / ff;
    return answer;
}