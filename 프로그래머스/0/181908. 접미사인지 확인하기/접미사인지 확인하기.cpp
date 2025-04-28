#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    string str = "";
    for(int i = my_string.size() - 1; i >=0; i--) {
        str = my_string[i] + str;
        if(str == is_suffix) {
            return 1;
        }
    }
    
    return 0;
}