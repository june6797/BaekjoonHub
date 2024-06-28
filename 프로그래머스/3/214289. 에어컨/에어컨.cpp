#include <bits/stdc++.h>
using namespace std;

int dp[1001][51];
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 1234567890;
    temperature += 10;
    t1 += 10;
    t2 += 10;
    int len = onboard.size();
    for(int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 50; j++) {
            dp[i][j] = 987654321;
        }
    }
    dp[0][temperature] = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j <= 50; j++) {
            if (onboard[i] == 1 &&
               (j < t1 || j > t2)) {
                continue;
            }
            int temp = j;
            if (j < temperature && j < 50) {
                temp++;
            }
            else if ( j > temperature && j > 0) {
                temp--;
            }
            
            dp[i + 1][temp] = min(dp[i + 1][temp], dp[i][j]);
            if (j > 0) {
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], a + dp[i][j]);
            }
            if (j < 50) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], a + dp[i][j]);
            }
            dp[i + 1][j] = min(dp[i + 1][j], b + dp[i][j]);
        }
        for (int i = 0; i <= 50; i++) {
            if (onboard[len - 1] == 1 && 
               (i < t1 || i > t2)) {
                continue;
            }
            answer = min(answer, dp[len - 1][i]);
        }
    }
    return answer;
}