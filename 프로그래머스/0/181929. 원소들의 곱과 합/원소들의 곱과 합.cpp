#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int a = 0, b = 1;
    for(int i = 0;i < num_list.size(); i++) {
        a += num_list[i];
        b *= num_list[i];
    }
    if(a* a > b) {
        return 1;
    }
    return 0;
}