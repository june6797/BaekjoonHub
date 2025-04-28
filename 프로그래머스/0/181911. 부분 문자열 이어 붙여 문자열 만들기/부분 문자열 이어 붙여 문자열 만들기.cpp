#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    for(int i = 0; i < parts.size(); i++) {
        int s = parts[i][0];
        int e = parts[i][1];
        for(int j = s; j <= e; j++) {
            answer+=my_strings[i][j];
        }
    }
    return answer;
}