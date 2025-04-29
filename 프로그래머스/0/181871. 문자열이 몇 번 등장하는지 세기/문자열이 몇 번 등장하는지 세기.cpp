#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    if(myString.size() < pat.size()) {
        return 0;
    }
    for(int i = 0; i <= myString.size() - pat.size(); i++) {
        if(myString[i] == pat[0]) {
            bool check = true;
            for(int j = i; j < i + pat.size(); j++) {
                if(myString[j] != pat[j - i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                answer++;
            }
        }
    }
    
    return answer;
}