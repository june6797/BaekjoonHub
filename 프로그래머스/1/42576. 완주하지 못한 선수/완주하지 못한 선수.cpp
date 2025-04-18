#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    
    for (int i = 0; i < participant.size(); i++) {
        m[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }
    for (int i = 0; i < participant.size(); i++) {
        if(m[participant[i]] != 0){
            answer = participant[i];
        }
    }
    return answer;
}