#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(int i = 0;i < intStrs.size(); i++) {
        string str = "";
        for(int j = s; j <= s + l - 1; j++) {
           str += intStrs[i][j];
        }
        int t = stoi(str);
        if(t > k) {
            answer.push_back(t);
        }
    }
    return answer;
}