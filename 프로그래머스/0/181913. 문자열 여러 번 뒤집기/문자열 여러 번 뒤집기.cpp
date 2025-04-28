#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    for(int i = 0; i <queries.size(); i++) {
        int s = queries[i][0];
        int e = queries[i][1];
        string str = "";
        for(int j = e; j >= s; j--) {
            str += my_string[j];
        }
        for(int j = s; j <= e; j++) {
            my_string[j] = str[j - s];
        }
        
    }
    return my_string;
}