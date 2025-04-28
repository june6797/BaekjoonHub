#include <string>
#include <vector>

using namespace std;
bool check(int a) {
    string str = to_string(a);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != '0' && str[i] != '5') {
            return false;
        }
    }
    return true;
}
vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i = l; i <= r; i++) {
        if(check(i)) {
            answer.push_back(i);
        }
    }
    if(answer.size() == 0) {
        answer.push_back(-1);
    }
    return answer;
}