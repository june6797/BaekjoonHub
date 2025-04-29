#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string str="";
    for(int i = 0; i < myString.size(); i++ ) {
        if(myString[i] == 'x') {
            if(str != ""){
            answer.push_back(str);
            str = "";
            }
        }
        else {
            str += myString[i];
        }
    }
    if(str!=""){
    answer.push_back(str);
    }
    sort(answer.begin(), answer.end());
    return answer;
}