#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    bool arr[101] = {0,};
    for(int i = 0; i < indices.size(); i++) {
        arr[indices[i]] = 1;
    }
    for(int i = 0; i < my_string.size(); i++) {
        if(!arr[i]) {
            answer += my_string[i];
        }
    }
    return answer;
}