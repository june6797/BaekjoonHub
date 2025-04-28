#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    string str = "";
    for(int i = 0; i < my_string.size(); i++) {
        str = str + my_string[i];
        if(str == is_prefix) {
            return 1;
        }
    }
    return 0;
}