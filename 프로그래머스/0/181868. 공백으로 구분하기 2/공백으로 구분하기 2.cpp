#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string str= "";
    for(int i = 0; i < my_string.size(); i++) {
        if(my_string[i] == ' ' && str != "") {
            answer.push_back(str);
            str = "";
        }
        else {
            if(my_string[i] != ' ') {
            str += my_string[i];
            }
        }
    }
    if(str!= ""){
    answer.push_back(str);
    }
    return answer;
}